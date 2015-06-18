#include "SineVelocitySimpleMelody.h"
SineVelocitySimpleMelody::SineVelocitySimpleMelody() {
      first_pitch = 0;
      last_pitch = 0;
  }
void SineVelocitySimpleMelody::SetFirstPitch(int f)
{
    first_pitch = f;
    last_pitch = f;
}
int SineVelocitySimpleMelody::GetNextPitch(int p)
{
    int cur_pitch = p;
    if (cur_pitch - 7 > last_pitch)
    {
        cur_pitch -= 12;
    }
    last_pitch = cur_pitch;
    return cur_pitch;
}
int SineVelocitySimpleMelody::GetVel(double al)
{
    return (int)(vel_from + ((sin(al * period + phase) + 1.0) / 2.0) * (vel_to - vel_from));
}
void SineVelocitySimpleMelody::render(RenderPart *p)
{
    int tempo = p->getTempo() + this->rndInt(-50, 50);
    phase = this->rndFloat(-1, 1);
    period = this->rndFloat(p->getUniquePart()->getMetrum() / 8.0, p->getUniquePart()->getMetrum());
    vel_from = this->rndInt(30, 50);
    vel_to = this->rndInt(110, 120);
    double delta = 0.5;
    if (tempo > 150)
    {
        delta = 1.0;
    }
    if (tempo < 60)
    {
        delta = 0.25;
    }
    Time t = this->createTime(p->getStartBar(), 0);
    int patternLength=this->rndInt(3, 8);
    vector<int8_t> pattern;

    for (int i = 0; i < patternLength; ++i )
    {
        if (this->rndInt(0, 4) == 0)
        {
            pattern.push_back(-2);
        }
        else
        {
            pattern.push_back(this->rndInt(-1, 1));            
        }
    }
    int n = 0;
    this->SetFirstPitch(p->getHarmonicEventPitch(0, 0));
    double al = 0;
    while (t.mBar < p->getEndBar())
    {
        int harm = p->getHarmonic(t);
        int pit = this->GetNextPitch(p->getHarmonicEventPitch(harm, 0));
        if (pattern[n % patternLength] == 0)
        {
            p->addNote(t, this->createTime(t.mBar, t.mPos + delta / 2.0), pit, this->GetVel(al));
        }
        if (pattern[n % patternLength] == 1)
        {
            p->addNote(t, this->createTime(t.mBar, t.mPos + delta / 2.0), p->alignPitch(pit, 7), this->GetVel(al));
        }
        if (pattern[n % patternLength] == -1)
        {
            p->addNote(t, this->createTime(t.mBar, t.mPos + delta / 2.0), p->alignPitch(pit, -7), this->GetVel(al));
        }
        t.mPos += delta;
        al += delta;
        if (t.mPos >= p->getUniquePart()->getMetrum())
        {
            t.mPos = 0;
            t.mBar++;
        }
        n++;
    }
//    delete pattern;
}
