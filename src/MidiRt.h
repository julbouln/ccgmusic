#ifndef MIDIRT_H
#define MIDIRT_H
#include "Common.h"
#include <queue>
#include <ctime>

#include "MidiDriver.h"
#include "RtMidi.h"

using namespace std;

class MidiRt : public MidiDriver {
	RtMidiOut *midiout;
	long currentTime;

	double ticksToTime(long t);
	long curMsTime();
public:
	MidiRt(int port);
	~MidiRt();

	void process(bool);

	void finish();

	void setTrackName(int track, string name);

	void sendTempo(long time, int track, int tempo);
	void sendControlChange(long time, int track, int chan, int ctrl, int val);
	void sendNoteOn(long time, int track, int chan, int note, int velocity);
	void sendNoteOff(long time, int track, int chan, int note, int velocity);
	void sendProgramChange(long time, int track, int chan, int val);

	class QueueMessage {
		vector<unsigned char> message;
		long timestamp;
	public:
		void setTime(long t) {timestamp=t;};
		long getTime() {return timestamp;};
		vector<unsigned char> * getMessage() {return &message;};
		class Comparator {
		public:
			bool operator() (const QueueMessage &lm, const QueueMessage &rm) const
			  {
				return lm.timestamp > rm.timestamp; 
			};
		};
	};

		priority_queue<QueueMessage,vector<QueueMessage>,QueueMessage::Comparator> queueMessages;

};
#endif // MIDIRT_H
