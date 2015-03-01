#ifndef MIDIDRIVER_H
#define MIDIDRIVER_H
#include "Common.h"
#include <queue>

#define MIDI_PROGRAM_CHANGE 0xC0
#define MIDI_CONTROL_CHANGE 0xB0
#define MIDI_NOTE_ON 0x90
#define MIDI_NOTE_OFF 0x80

#define MIDI_ALL_NOTES_OFF 0x7B
#define MIDI_ALL_SOUND_OFF 0x78


using namespace std;
class MidiDriver {
	long currentTime;
	int tempo;
	float ticksToTime(long t);

public:
	    bool stopAsap;


	MidiDriver();
	virtual ~MidiDriver() {};
	virtual void process(bool finished);
	virtual void mute();

	virtual void msleep(int ms) {};

	virtual void setTrackName(int track, string name) {};
	virtual void sendTempo(long time, int track, int tempo);
	virtual void sendControlChange(long time, int track, int chan, int ctrl, int val);
	virtual void sendNoteOn(long time, int track, int chan, int note, int velocity);
	virtual void sendNoteOff(long time, int track, int chan, int note, int velocity);
	virtual void sendProgramChange(long time, int track, int chan, int val);

class QueueMessage {
//		vector<uint8_t> message;
		uint8_t message[3];
		uint8_t size;
		int timestamp;

	public:
		void setSize(int s) {
			size = s;
		};
		int getSize() {
			return size;
		};

		void setTime(int t) {
			timestamp = t;
		};
		int getTime() {
			return timestamp;
		};

		void setMessage(uint8_t pos, uint8_t msg) {
			message[pos] = msg;
		};

		uint8_t *getMessage() {
			return message;
		};
		class Comparator {
		public:
			bool operator() (const QueueMessage &lm, const QueueMessage &rm) const
			{
				return lm.timestamp > rm.timestamp;
			};
		};
	};


	priority_queue<QueueMessage, vector<QueueMessage>, QueueMessage::Comparator> queueMessages;
	virtual void sendMessage(QueueMessage *) {};
	virtual int getQueueSize() { 
		int size;
		this->mutexLock();
		size=queueMessages.size();
 		this->mutexUnlock();
		return size;
	};

	virtual void wait() {
		while(1)
        {
            int size=this->getQueueSize();
            if(size > max_queue_size) {
                        //printf("wait for driver queue %d\n",size);
                        this->msleep(100);
            } else {
                break;
            }

        }

	}

	void launch() {
	while(this->getQueueSize() <= min_queue_size)
    {
      this->msleep(10);
    }
    //printf("launch process\n");
    this->process(true);

    this->mute();
	}

	virtual void mutexLock() {};
	virtual void mutexUnlock() {};


	virtual void clear() {
		 while (!queueMessages.empty()) {
    	    queueMessages.pop();
	    }
	};
	int min_queue_size;
	int max_queue_size;


};
#endif // MIDIDRIVER_H
