#include "MidiDriver.h"


MidiDriver::MidiDriver() {
    currentTime = 0;
    tempo=120;
    stopAsap=false;

    min_queue_size=0;
    max_queue_size=INT_MAX;
}

float MidiDriver::ticksToTime(long t) {
    return (float)t * (float)tempo/1000.0/48.0;

}

void MidiDriver::sendTempo(long time, int track, int tempo)
{
    this->tempo=tempo;
}


void MidiDriver::mute() {
    for (int c = 0; c < 16; c++) {
//        this->msleep(50);

        QueueMessage qm;
        qm.setMessage(0,MIDI_CONTROL_CHANGE + c);
        qm.setMessage(1,MIDI_ALL_NOTES_OFF);
        qm.setMessage(2,0);
        qm.setSize(3);
        this->sendMessage( &qm );
    }
}
void MidiDriver::process(bool finished) {
    long processTime = 0;

    int size=this->getQueueSize();

    if (size > 0) {

        QueueMessage m = queueMessages.top();
        printf("MidiDriver::process %d * %d = %d bytes\n",size,sizeof(m),size*sizeof(m));

        float mTime = (float)this->ticksToTime(m.getTime());
 //       printf("MidiDriver::process desynchro %ld\n", (long)mTime - currentTime);

        currentTime = (long)mTime;
//        printf("MidiDriver::process (%d messages) RT %ld\n", size, currentTime);

    }

    while (1) {
        int size=this->getQueueSize();
        if(size > 0) {
//        printf("MidiDriver::process (%d messages) RT %ld\n", size, processTime);

        QueueMessage m = queueMessages.top();

        float msgTime = (float)this->ticksToTime(m.getTime());
        float msec = msgTime - processTime - currentTime;

        if (msec < 0)
            msec = 0;

        this->msleep(msec);
        this->sendMessage(&m);
        queueMessages.pop();

        processTime += msec;

        if(stopAsap) {
            this->clear();
            return;
        }
        } else {
            break;
        }

    }
    currentTime += processTime;
}

void MidiDriver::sendControlChange(long time, int track, int chan, int ctrl, int val)
{
    QueueMessage qm;
    uint8_t *m = qm.getMessage();
    m[0]=MIDI_CONTROL_CHANGE + chan;
    m[1]=ctrl;
    m[2]=val;

    qm.setSize(3);
    qm.setTime(time);
    queueMessages.push(qm);
}
void MidiDriver::sendNoteOn(long time, int track, int chan, int note, int velocity)
{
    QueueMessage qm;
    uint8_t *m = qm.getMessage();
    m[0]=MIDI_NOTE_ON + chan;
    m[1]=note;
    m[2]=velocity;

    qm.setSize(3);
    qm.setTime(time);
    queueMessages.push(qm);

}
void MidiDriver::sendNoteOff(long time, int track, int chan, int note, int velocity)
{
    QueueMessage qm;
    uint8_t *m = qm.getMessage();
    m[0]=MIDI_NOTE_OFF + chan;
    m[1]=note;
    m[2]=velocity;

    qm.setSize(3);
    qm.setTime(time);
    queueMessages.push(qm);

}
void MidiDriver::sendProgramChange(long time, int track, int chan, int val)
{
    QueueMessage qm;
    uint8_t *m = qm.getMessage();
    m[0]=MIDI_PROGRAM_CHANGE + chan;
    m[1]=val;

    qm.setSize(2);
    qm.setTime(time);
    queueMessages.push(qm);

}