#include "MidiFileWriter.h"

MidiFileWriter::MidiFileWriter(string fn)
{
	MIDITimedBigMessage m; 
	filename=fn;
    int clks_per_beat = 48; // number of ticks in crotchet (1...32767)
    numTracks = 16; // tracks 0 and 1

    midiTracks = new MIDIMultiTrack( numTracks );
    midiTracks->SetClksPerBeat( clks_per_beat );

    clockT = 0;
    m.SetTime( clockT );

    m.SetTimeSig( 4, 2); // measure 4/4 (default values for time signature)
    midiTracks->GetTrack( 0 )->PutEvent( m );

}

MidiFileWriter::~MidiFileWriter()
{
	
    delete midiTracks;
}

void MidiFileWriter::finish() {
    MIDITimedBigMessage m; 
    midiTracks->SortEventsOrder();

    MIDIFileWriteStreamFileName out_stream( filename.c_str() );
    // then output the stream like my example does, except setting num_tracks to match your data
    if ( out_stream.IsValid() )
    {
        // the object which takes the midi tracks and writes the midifile to the output stream
        MIDIFileWriteMultiTrack writer( midiTracks, &out_stream );
        // write the output file
        if ( writer.Write( numTracks ) )
        {
//            cout << "OK writing file " << filename << endl;
        }
        else
        {
            cerr << "Error writing file " << filename << endl;
        }
    }
    else
    {
        cerr << "Error opening file " << filename << endl;
    }
}


void MidiFileWriter::setTrackName(int track, string name) {
	    clockT = 0;
	    midiTracks->GetTrack( track )->PutTextEvent(clockT, META_TRACK_NAME, name.c_str());
}


void MidiFileWriter::sendTempo(long time, int track, int tempo)
{
	MIDITimedBigMessage m; 
    clockT = time;
    m.SetTime( clockT );
    m.SetTempo(tempo);
    midiTracks->GetTrack( track )->PutEvent( m );
}
void MidiFileWriter::sendControlChange(long time, int track, int chan, int ctrl, int val)
{
	MIDITimedBigMessage m; 
    clockT = time;
    m.SetTime( clockT );
    m.SetControlChange( chan, ctrl, val);
    midiTracks->GetTrack( track )->PutEvent( m );
}
void MidiFileWriter::sendNoteOn(long time, int track, int chan, int note, int velocity)
{
	MIDITimedBigMessage m; 
    clockT = time;
    m.SetTime( clockT );
    m.SetNoteOn( chan, note, velocity );
    midiTracks->GetTrack( track )->PutEvent( m );
}
void MidiFileWriter::sendNoteOff(long time, int track, int chan, int note, int velocity)
{
	MIDITimedBigMessage m; 
    clockT = time;
    m.SetTime( clockT );
    m.SetNoteOff( chan, note, velocity );
    midiTracks->GetTrack( track )->PutEvent( m );
}
void MidiFileWriter::sendProgramChange(long time, int track, int chan, int val)
{
	MIDITimedBigMessage m; 
    clockT = time;
    m.SetTime( clockT );
    m.SetProgramChange( chan, val);
    midiTracks->GetTrack( track )->PutEvent( m );
}
