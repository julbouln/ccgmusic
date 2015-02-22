#ifndef MIDIFILEWRITER_H
#define MIDIFILEWRITER_H
#include "Common.h"

#include "MidiDriver.h"

#include "jdksmidi/world.h"
#include "jdksmidi/track.h"
#include "jdksmidi/multitrack.h"
#include "jdksmidi/filereadmultitrack.h"
#include "jdksmidi/fileread.h"
#include "jdksmidi/fileshow.h"
#include "jdksmidi/filewritemultitrack.h"
using namespace jdksmidi;
using namespace std;

class MidiFileWriter : public MidiDriver {
	string filename;
	int numTracks;
    MIDIClockTime clockT; // time in midi ticks

    MIDIMultiTrack *midiTracks; // the object which will hold all the tracks
    
public:
	MidiFileWriter(string fn);
	~MidiFileWriter();

	void finish();
	void setTrackName(int track, string name);

	void sendTempo(long time, int track, int tempo);
	void sendControlChange(long time, int track, int chan, int ctrl, int val);
	void sendNoteOn(long time, int track, int chan, int note, int velocity);
	void sendNoteOff(long time, int track, int chan, int note, int velocity);
	void sendProgramChange(long time, int track, int chan, int val);
};
#endif // MIDIFILEWRITER_H
