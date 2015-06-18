#include "MidiDriver.h"


MidiDriver::MidiDriver() {
    currentTime = 0;
    tempo = 500000;
    ticksPerQuarterNote = 48;
    stop = false;
    pause = false;

    min_queue_size = 0;
    max_queue_size = INT_MAX;
}

float MidiDriver::ticksToTime(long t) {
//    return (float)t * (float)tempo / 1000.0 / 48.0;

    return ((float)t * (float)tempo) / ((float)ticksPerQuarterNote * 1000.0);
}

void MidiDriver::sendTempo(long time, int track, int tempo)
{
    this->tempo = tempo;
}


void MidiDriver::mute() {
    for (int c = 0; c < 16; c++) {
//        this->msleep(50);

        QueueMessage qm;
        qm.setMessage(0, MIDI_CONTROL_CHANGE + c);
        qm.setMessage(1, MIDI_ALL_NOTES_OFF);
        qm.setMessage(2, 0);
        qm.setSize(3);
        this->sendMessage( &qm );
    }
}
void MidiDriver::process(bool finished) {
    long processTime = 0;

    int size = this->getQueueSize();

    if (size > 0) {
        QueueMessage m;
        mutexLock();
        m = queueMessages.top();
        mutexUnlock();

//        printf("MidiDriver::process %d * %d = %d bytes\n", size, sizeof(m), size * sizeof(m));

        float mTime = (float)this->ticksToTime(m.getTime());
//       printf("MidiDriver::process desynchro %ld\n", (long)mTime - currentTime);

        currentTime = (long)mTime;
//        printf("MidiDriver::process (%d messages) RT %ld\n", size, currentTime);
  } else {
        currentTime=0;
  }

  
    while (1) {
        int size = this->getQueueSize();

        if (size > 0) {
            if (!this->getPause()) {
//        printf("MidiDriver::process (%d messages) RT %ld\n", size, processTime);

                QueueMessage m;
                mutexLock();
                m = queueMessages.top();
                mutexUnlock();

                float msgTime = (float)this->ticksToTime(m.getTime());
                float msec = msgTime - processTime - currentTime;

                if (msec < 0)
                    msec = 0;

                this->msleep(msec);
                this->sendMessage(&m);
                mutexLock();
                queueMessages.pop();
                mutexUnlock();

                processTime += msec;

                if (this->getStop()) { // clear current messages
                    this->clear();
                    break;
                }
            }
            else {
                this->mute();
                this->msleep(100);
            }

        } else {
            break;
        }

    }
    currentTime += processTime;
}

void MidiDriver::queueMessage(QueueMessage qm) {
    if (!this->getStop()) { // do not accept new message
        this->mutexLock();
        queueMessages.push(qm);
        this->mutexUnlock();
    }
}

void MidiDriver::sendControlChange(long time, int track, int chan, int ctrl, int val)
{

    QueueMessage qm;
    uint8_t *m = qm.getMessage();
    m[0] = MIDI_CONTROL_CHANGE + chan;
    m[1] = ctrl;
    m[2] = val;

    qm.setSize(3);
    qm.setTime(time);
    this->queueMessage(qm);
}
void MidiDriver::sendNoteOn(long time, int track, int chan, int note, int velocity)
{
    QueueMessage qm;
    uint8_t *m = qm.getMessage();
    m[0] = MIDI_NOTE_ON + chan;
    m[1] = note;
    m[2] = velocity;

    qm.setSize(3);
    qm.setTime(time);
    this->queueMessage(qm);

}
void MidiDriver::sendNoteOff(long time, int track, int chan, int note, int velocity)
{
    QueueMessage qm;
    uint8_t *m = qm.getMessage();
    m[0] = MIDI_NOTE_OFF + chan;
    m[1] = note;
    m[2] = velocity;

    qm.setSize(3);
    qm.setTime(time);
    this->queueMessage(qm);

}
void MidiDriver::sendProgramChange(long time, int track, int chan, int val)
{
    QueueMessage qm;
    uint8_t *m = qm.getMessage();
    m[0] = MIDI_PROGRAM_CHANGE + chan;
    m[1] = val;

    qm.setSize(2);
    qm.setTime(time);
    this->queueMessage(qm);

}