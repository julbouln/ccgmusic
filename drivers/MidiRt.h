#ifndef MIDIRT_H
#define MIDIRT_H
#include "Common.h"
#include <ctime>

#include "MidiDriver.h"
#include "RtMidi.h"



using namespace std;

class MidiRt : public MidiDriver {
	RtMidiOut *midiout;

	pthread_mutex_t mutex;

	int curMsTime();
public:
	MidiRt(int port);
	~MidiRt();

	void msleep(int);
	
	void setTrackName(int track, string name);

	vector<uint8_t> messageToRt(QueueMessage *);
	void sendMessage(QueueMessage *);

	void mutexLock();
	void mutexUnlock();


};
#endif // MIDIRT_H
