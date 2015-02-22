#ifndef MIDIDRIVER_H
#define MIDIDRIVER_H
#include "Common.h"

using namespace std;
class MidiDriver {
public:
	virtual ~MidiDriver() {};
	virtual void process(bool finished) {};
	virtual void finish() {};
	virtual void setTrackName(int track, string name) {};
	virtual void sendTempo(long time, int track, int tempo) {};
	virtual void sendControlChange(long time, int track, int chan, int ctrl, int val) {};
	virtual void sendNoteOn(long time, int track, int chan, int note, int velocity) {};
	virtual void sendNoteOff(long time, int track, int chan, int note, int velocity) {};
	virtual void sendProgramChange(long time, int track, int chan, int val) {};
};
#endif // MIDIDRIVER_H
