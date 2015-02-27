#include "MidiDriver.h"


MidiDriver::MidiDriver() {
        currentTime = 0;
    tempo=120;
}

float MidiDriver::ticksToTime(long t) {
    return (float)t * (float)tempo/1000.0/48.0;

}

void MidiDriver::sendTempo(long time, int track, int tempo)
{
    this->tempo=tempo;
}


void MidiDriver::process(bool finished) {
    long processTime = 0;

    if (!queueMessages.empty()) {
        QueueMessage m = queueMessages.top();
        float mTime = (float)this->ticksToTime(m.getTime());
        printf("MidiDriver::process desynchro %ld\n", (long)mTime - currentTime);

        currentTime = (long)mTime;
        printf("MidiDriver::process (%d messages) RT %ld\n", queueMessages.size(), currentTime);
    }

    while (!queueMessages.empty()) {

        QueueMessage m = queueMessages.top();

        float msgTime = (float)this->ticksToTime(m.getTime());
        float msec = msgTime - processTime - currentTime;

        if (msec < 0)
            msec = 0;

        this->msleep(msec);
        this->sendMessage(&m);
        queueMessages.pop();

        processTime += msec;

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