#include "SimpleRandomRythm.h"

void SimpleRandomRythm::generateRythm(UniquePhrase *up)
{
    int bars = up->getBars();
    if (up->endsSentence())
    {
        bars--;
    }
    int appoggiatura = this->rndInt(0, 4);
    if (appoggiatura == 0)
    {
        up->addEvent(this->createTime(-1, up->getMetrum() - 1), this->createTime(-1, up->getMetrum()));
    }
    else
    {
        if (appoggiatura == 1)
        {
            up->addEvent(this->createTime(-1, up->getMetrum() - 0.5), this->createTime(-1, up->getMetrum()));
        }
        else
        {
            if (appoggiatura == 2)
            {
                up->addEvent(this->createTime(-1, up->getMetrum() - 1), this->createTime(-1, up->getMetrum() - 0.5));
                up->addEvent(this->createTime(-1, up->getMetrum() - 0.5), this->createTime(-1, up->getMetrum()));
            }
        }
    }
    for (int i = 0; i < bars; ++i )
    {
        for (int b = 0; b < up->getMetrum(); b += 1    )
        {
            int t = this->rndInt(0, 1);
            if (t == 0)
            {
                up->addEvent(this->createTime(i, b), this->createTime(i, b + 1));
            }
            if (t == 1)
            {
                up->addEvent(this->createTime(i, b), this->createTime(i, b + 0.5));
                up->addEvent(this->createTime(i, b + 0.5), this->createTime(i, b + 1));
            }
        }
    }
    if (up->endsSentence())
    {
        up->addEvent(this->createTime(up->getBars() - 1, 0), this->createTime(up->getBars() - 1, up->getMetrum()));
    }
}
