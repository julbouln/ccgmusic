#include "PunkGuitarChords.h"


bool *PunkGuitarChords::GenerateAccents(int count, float speed, bool first)
{
//    printf("PunkGuitarChords::GenerateAccents: %f %d\n",speed,count);

    bool *accents = new bool[count];
    for (int i = 0; i < count; i++)
    {
        if (first && i == 0)
        {
            accents[i] = true;
        }
        else
        {
            if (i > 0 && accents[i - 1])
            {
                accents[i] = false;
            }
            else
            {
                if (this->rndInt(0, 1) == 0)
                {
                    accents[i] = true;
                }
                else
                {
                    accents[i] = false;
                }
            }
        }
    }
    return accents;
}

void PunkGuitarChords::PlacePunkChord(RenderPart *p, Time t, Time t2, int vel, int harm, bool accent, int swap_down)
{
    int pit[3];
    pit[0] = p->getHarmonicEventPitch(harm, 0);
    pit[1] = p->alignPitch(p->getHarmonicEventPitch(harm, 0), 4);
    pit[2] = p->alignPitch(p->getHarmonicEventPitch(harm, 0), 7);
    if (last_harm < -100)
    {
        last_harm = harm;
        low_pit = pit[0] + this->rndInt(-4, 10);
    }
    if (last_harm != harm)
    {
        last_harm = harm;
        low_pit = pit[0] + this->rndInt(-3, 5);
    }
    while (pit[0] > low_pit)
    {

        int odl = pit[0] - low_pit;

        if (odl >= abs(low_pit - (pit[1] - 12)))
        {
            int tmp = pit[2];
            pit[2] = pit[1];
            pit[1] = tmp;
            tmp = pit[1];
            pit[1] = pit[0];
            pit[0] = tmp;
            pit[0] = pit[2] - 12;
        }
        else
        {
            break;
        }

    }

    int odl = pit[1] - pit[0];
    if (odl != 6)
    {
        if (swap_down == 1)
        {
            p->addNote(t, t2, pit[0], vel);
            p->addNote(t, t2, pit[1] - 12, vel);
            p->addNote(t, t2, pit[1], vel);
        }
        else
        {
            p->addNote(t, t2, pit[0], vel);
            p->addNote(t, t2, pit[1], vel);
            p->addNote(t, t2, pit[2], vel);
            if (this->rndInt(0, 1) == 0 && accent)
            {
                p->addNote(t, t2, pit[1] + 12, vel);
            }
        }
    }
    else
    {
        if (accent)
        {
            p->addNote(t, t2, p->getHarmonicEventPitch(harm, 0), vel);
            p->addNote(t, t2, p->alignPitch(p->getHarmonicEventPitch(harm, 0), 4) - 12, vel / 3);
            p->addNote(t, t2, p->getHarmonicEventPitch(harm, 0) - 12, vel);
        }
        else
        {
            p->addNote(t, t2, p->getHarmonicEventPitch(harm, 0), vel);
            p->addNote(t, t2, p->getHarmonicEventPitch(harm, 0) - 12, vel);
        }
    }
}
void PunkGuitarChords::DoMode1(RenderPart *p)
{
    Time tOuter = this->createTime(p->getStartBar(), 0);
    float speed = 0.5;
    if (p->getTempo() < 110)
    {
        speed /= 2.0;
    }
    int wyprz = this->rndInt(0, 2);
    int speed_up = this->rndInt(0, 1);
    int reset = 8;
    if (this->rndInt(0, 1) == 0)
    {
        reset = 4;
    }
    this->resetSeed();
    
    int accentsLength = (int)(p->getUniquePart()->getMetrum() / speed);
    bool *accents = this->GenerateAccents(accentsLength, speed, true);
    int reset_counter = 0;
    for (int i = p->getStartBar(); i < p->getEndBar(); i++)
    {
        Time t = this->createTime(i, 0);
        for (int a = 0; a < accentsLength; a++)
        {
            int harm = p->getHarmonic(t);
            if (wyprz > 0 && a == accentsLength - 1)
            {
                if (wyprz == 1 || (wyprz == 2 && this->rndInt(0, 1) == 0))
                {
                    harm = p->getHarmonic(this->createTime(t.mBar + 1, 0));
                }
            }
            Time t2;
            int vel = 88;
            if (accents[a])
            {
                t2 = this->createTime(t.mBar, t.mPos + 0.8 * speed);
                vel = 116;
            }
            else
            {
                t2 = this->createTime(t.mBar, t.mPos + speed * 0.4);
            }
            this->PlacePunkChord(p, t, t2, vel, harm, accents[a], 0);
            if (speed_up > 0 && !accents[a] && a == (accentsLength - 1))
            {
                this->PlacePunkChord(p, this->createTime(t.mBar, t.mPos + speed / 2.0), this->createTime(t2.mBar, t2.mPos + speed * 0.4), vel, harm, accents[a], 0);
            }
            t.mPos += speed;
        }
        reset_counter++;
        if (reset_counter >= reset)
        {
            reset_counter = 0;
            this->resetSeed();
            last_harm = -1000;
            delete accents;
            accentsLength = (int)(p->getUniquePart()->getMetrum() / speed);
            accents = this->GenerateAccents(accentsLength, speed, true);
        }
        else
        {
            delete accents;
            accentsLength = (int)(p->getUniquePart()->getMetrum() / speed);
            accents = this->GenerateAccents(accentsLength, speed, false);
        }
    }
    delete accents;
}
void PunkGuitarChords::DoMode2(RenderPart *p)
{
    float step = 2;
    if (p->getUniquePart()->getMetrum() == 3)
    {
        step = 2;
        if (p->getTempo() < 120)
        {
            step /= 2.0;
        }
    }
    else
    {
        if (p->getTempo() < 110)
        {
            step /= 2.0;
        }
    }
    int swap_down = this->rndInt(0, 1);
    for (int i = p->getStartBar(); i < p->getEndBar(); i++)
    {
        for (float m = 0; m + step * 0.9 < p->getUniquePart()->getMetrum(); m += step)
        {
            Time t = this->createTime(i, m);
            int harm = p->getHarmonic(t);
            if (this->rndInt(0, 2) != 0)
            {
                this->PlacePunkChord(p, t, this->createTime(i, m + step / 2.0), 120, harm, true, swap_down);
            }

            else
            {
                this->PlacePunkChord(p, t, this->createTime(i, m + step / 4.0), 120, harm, true, swap_down);
                this->PlacePunkChord(p, this->createTime(i, m + step / 4.0), this->createTime(i, m + step / 2.0), 120, harm, true, swap_down);
            }
            this->PlacePunkChord(p, this->createTime(i, m + step / 2.0), this->createTime(i, m + step / 2.0 + 0.1), 88, harm, false, swap_down);
            if ((i != p->getStartBar() || m > 0) && this->rndInt(0, 4) != 0)
            {
                if (this->rndInt(0, 1) == 0)
                {
                    if (m > 0)
                    {
                        harm = p->getHarmonic(this->createTime(i, m - 0.1));
                    }
                    else
                    {
                        harm = p->getHarmonic(this->createTime(i - 1, p->getUniquePart()->getMetrum() - step / 4.0 + m));
                    }
                }
                if (this->rndInt(0, 3) != 0)
                {
                    this->PlacePunkChord(p, this->createTime(i - 1, p->getUniquePart()->getMetrum() - step / 4.0 + m), t, 120, harm, true, swap_down);
                }
                else
                {
                    this->PlacePunkChord(p, this->createTime(i - 1, p->getUniquePart()->getMetrum() - step / 4.0 + m), this->createTime(i - 1, p->getUniquePart()->getMetrum() - step / 4.0 + 0.1 + m), 88, harm, false, swap_down);
                    this->PlacePunkChord(p, this->createTime(i - 1, p->getUniquePart()->getMetrum() - step / 8.0 + m), this->createTime(i - 1, p->getUniquePart()->getMetrum() - step / 8.0 + 0.1 + m), 88, harm, false, swap_down);
                }
            }
            if (swap_down == 0)
            {
                swap_down = 1;
            }
            else
            {
                swap_down = 0;
            }
        }
    }
}
void PunkGuitarChords::DoMode3(RenderPart *p)
{
    float step = 1.0;


    if (p->getTempo() < 140)
    {
        step /= 2.0;
    }
    if (p->getTempo() < 60)
    {
        step /= 2.0;
    }
    Time t = this->createTime(p->getStartBar(), 0);
    int swap_down[] = {this->rndInt(0, 1), this->rndInt(0, 1)};
    bool accent[] = {false, false};
    if (this->rndInt(0, 1) == 0)
    {
        accent[0] = true;
    }
    if (this->rndInt(0, 1) == 0)
    {
        accent[1] = true;
    }
    if (this->rndInt(0, 2) != 0)
    {
        accent[0] = false;
        accent[1] = false;
        swap_down[0] = 0;
        swap_down[1] = 0;
    }
    for (int i = p->getStartBar(); i < p->getEndBar(); i++)
    {
        for (float m = 0; m < p->getUniquePart()->getMetrum(); m += step    )
        {
//            printf("PunkGuitarChords::DoMode3 double loop %f\n",m);

            int harm = p->getHarmonic(this->createTime(i, m));
            if (this->rndInt(0, 3) != 0 || (m < 0.1 && this->rndInt(0, 1) == 0))
            {
                this->PlacePunkChord(p, this->createTime(i, m), this->createTime(i, m + step), 125, harm, accent[0], swap_down[0]);
            }
            else
            {
                this->PlacePunkChord(p, this->createTime(i, m), this->createTime(i, m + step / 2), 120, harm, accent[1], swap_down[1]);
                this->PlacePunkChord(p, this->createTime(i, m + step / 2), this->createTime(i, m + step), 120, harm, accent[1], swap_down[1]);
            }
        }
    }
}
void PunkGuitarChords::render(RenderPart *p)
{
    int mode = p->getParam(RenderEvent::MODE);
    if (mode == 0)
    {
        mode = this->rndInt(0, 2);
    }
    else
    {
        mode--;
    }
    last_harm = -1000;

    switch(mode) {
        case 0:
            this->DoMode1(p);
            break;
        case 1:
            this->DoMode2(p);
            break;
        case 2:
            this->DoMode3(p);
            break;
    }
}
