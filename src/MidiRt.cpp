#include "MidiRt.h"
#include <unistd.h>
#include <sys/time.h>

#define PROGRAM_CHANGE 0xC0
#define CONTROL_CHANGE 0xB0
#define NOTE_ON 0x90
#define NOTE_OFF 0x80

#define ALL_NOTES_OFF 0x7B
#define ALL_SOUND_OFF 0x78

MidiRt::MidiRt(int port)
{
    midiout = new RtMidiOut();
    midiout->openPort( port );
    startTime=this->curMsTime();
}

MidiRt::~MidiRt()
{
    delete midiout;
}

void MidiRt::finish() {
    for(int c=0;c<16;c++) {
    usleep(1000*50);

        vector<unsigned char> m;
        m.push_back(CONTROL_CHANGE+c);
        m.push_back(ALL_NOTES_OFF);
        m.push_back(0);
        midiout->sendMessage( &m );
//        printf("SENT %d %d %d\n",m.at(0),m.at(1),m.at(2));

    }

}

long MidiRt::curMsTime() {
    struct timeval tp;
    gettimeofday(&tp,NULL);
    return (tp.tv_sec * 1000 + tp.tv_usec / 1000);
}

double MidiRt::ticksToTime(long t) {
    return (double)t*(60000.0 / (120.0 * 48.0));
}

void MidiRt::process(bool finished) {
    double delay=1.0;
    double rtDelay=100.0;
    bool postpone=false;
    double currentTime=(double)this->curMsTime();
//            printf("MidiRt::process %d messages in queue (%f)\n",queueMessages.size(),(currentTime-startTime));

    while(!postpone) {
  
        currentTime=(double)this->curMsTime();
        QueueMessage m=queueMessages.top();
        double realTime=(currentTime-startTime);
        double msgTime=(double)this->ticksToTime(m.getTime())+rtDelay;
        double msec=rtDelay + msgTime - realTime;

        if(msgTime <= realTime) {
          if(!queueMessages.empty()) {

//            printf("MidiRt::process (%d messages) RT %fms %f (%ld/%f)\n",queueMessages.size(),msec,currentTime-startTime,m.getTime(),msgTime);
            if(msec < 0.0) {
                if(msec < -3.0) 
                {
                    printf("MidiRt::process warning %fms RT delay\n",msec);
                }
              msec=0.0;
            }

              usleep(msec*1000);
              midiout->sendMessage( m.getMessage() );
              queueMessages.pop();
          } else {
            usleep(delay*1000);
            postpone=true;
          }
  
        }
        else {
            if(!finished) {
//             printf("MidiRt::process postpone %f > %f\n",msgTime,realTime);
             usleep(delay*1000);
             postpone=true;
         }
         }
    }

}

void MidiRt::setTrackName(int track, string name) {
}

void MidiRt::sendTempo(long time, int track, int tempo)
{
}
void MidiRt::sendControlChange(long time, int track, int chan, int ctrl, int val)
{
    QueueMessage qm;
    vector<unsigned char> *m=qm.getMessage();
    m->push_back(CONTROL_CHANGE+chan);
    m->push_back(ctrl);
    m->push_back(val);

    qm.setTime(time);
    queueMessages.push(qm);
}
void MidiRt::sendNoteOn(long time, int track, int chan, int note, int velocity)
{
    QueueMessage qm;
    vector<unsigned char> *m=qm.getMessage();
    m->push_back(NOTE_ON+chan);
    m->push_back(note);
    m->push_back(velocity);

    qm.setTime(time);
    queueMessages.push(qm);

}
void MidiRt::sendNoteOff(long time, int track, int chan, int note, int velocity)
{
        QueueMessage qm;
    vector<unsigned char> *m=qm.getMessage();
    m->push_back(NOTE_OFF+chan);
    m->push_back(note);
    m->push_back(velocity);

    qm.setTime(time);
    queueMessages.push(qm);

}
void MidiRt::sendProgramChange(long time, int track, int chan, int val)
{
    QueueMessage qm;
    vector<unsigned char> *m=qm.getMessage();
    m->push_back(PROGRAM_CHANGE+chan);
    m->push_back(val);

    qm.setTime(time);
    queueMessages.push(qm);

}
