#include "MidiRt.h"
#include <unistd.h>
#include <sys/time.h>


MidiRt::MidiRt(int port)
{
    midiout = new RtMidiOut();
    midiout->openPort( port );
}

MidiRt::~MidiRt()
{
    delete midiout;
}

void MidiRt::msleep(int ms) {
    usleep(ms * 1000);
}


int MidiRt::curMsTime() {
    struct timeval tp;
    gettimeofday(&tp, NULL);
    return (tp.tv_sec * 1000 + tp.tv_usec / 1000);
}

void MidiRt::sendMessage(QueueMessage *qm)
{

    vector<uint8_t> tmsg=messageToRt(qm);
    midiout->sendMessage( &tmsg );
}
vector<uint8_t> MidiRt::messageToRt(QueueMessage *qm)
{
    uint8_t *m = qm->getMessage();
    vector<uint8_t> rt;
    for(int i=0;i<qm->getSize();i++)
        rt.push_back(m[i]);
    return rt;
}

void MidiRt::setTrackName(int track, string name) {
}


