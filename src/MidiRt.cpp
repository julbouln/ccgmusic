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

void MidiRt::finish() {
    for (int c = 0; c < 16; c++) {
        usleep(1000 * 50);

        vector<unsigned char> m;
        m.push_back(MIDI_CONTROL_CHANGE + c);
        m.push_back(MIDI_ALL_NOTES_OFF);
        m.push_back(0);
        midiout->sendMessage( &m );
        //        printf("SENT %d %d %d\n",m.at(0),m.at(1),m.at(2));

    }

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


