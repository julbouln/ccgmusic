#include "SimpleSwingRythm.h"

void SimpleSwingRythm::generateRythm(UniquePhrase *up)
{
    int bars = up->getBars();
    if (up->endsSentence())
    {
        bars--;
    }
    bool must_follow = false;
    if (this->rndInt(0, 2) != 0)
    {
        if (this->rndInt(0, 1) == 0)
        {
            up->addEvent(this->createTime(-1, up->getMetrum() - 0.25), this->createTime(-1, up->getMetrum()));
            must_follow = true;
        }
        else
        {
            up->addEvent(this->createTime(-1, up->getMetrum() - 0.5), this->createTime(-1, up->getMetrum()));
            if (this->rndInt(0, 1) == 0)
            {
                must_follow = true;
            }
        }
    }
    for (int i = 0; i < bars; i++ )
    {
        int met = up->getMetrum();
        if (i == bars - 1)
        {
            met--;
        }
        for (int b = 0; b < met; b++ )
        {
            int t = this->rndInt(0, 3);
            if (must_follow)
            {
                t = this->rndInt(0, 2);
            }
            if (b == met - 1)
            {
                t = this->rndInt(1, 2);
            }
            if (t == 0)
            {
                up->addEvent(this->createTime(i, b), this->createTime(i, b + 0.75));
                up->addEvent(this->createTime(i, b + 0.75), this->createTime(i, b + 1));
                must_follow = true;
            }
            if (t == 1)
            {
                up->addEvent(this->createTime(i, b), this->createTime(i, b + 1));
                must_follow = false;
            }
            if (t == 2)
            {
                up->addEvent(this->createTime(i, b), this->createTime(i, b + 0.5));
                up->addEvent(this->createTime(i, b + 0.5), this->createTime(i, b + 1));
                must_follow = false;
            }
            if (t == 3)
            {
                if (this->rndInt(0, 1) == 0)
                {
                    up->addEvent(this->createTime(i, b + 0.5), this->createTime(i, b + 1));
                }
                else
                {
                    up->addEvent(this->createTime(i, b + 0.75), this->createTime(i, b + 1));
                    must_follow = true;
                }
            }
        }
    }
    if (up->endsSentence())
    {
        up->addEvent(this->createTime(up->getBars() - 1, 0), this->createTime(up->getBars() - 1, up->getMetrum()));
    }
}
