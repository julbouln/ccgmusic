#include "CcgMusic.h"
#include <stdio.h>
#include <sys/time.h>
#include <ctime>

#include "MidiFileWriter.h"
#include "MidiRt.h"

void dumpSize()
{
	printf("sizeof int %d\n",sizeof(int));
	printf("sizeof int8_t %d\n",sizeof(int8_t));
	printf("sizeof float %d\n",sizeof(float));
	printf("sizeof double %d\n",sizeof(double));

printf("sizeof Time %d\n",sizeof(Time));
printf("sizeof Note %d\n",sizeof(Note));
printf("sizeof QueueMessage %d\n",sizeof(MidiRt::QueueMessage));

printf("sizeof Event %d\n",sizeof(Event));

printf("sizeof ChromaticEvent %d\n",sizeof(ChromaticEvent));

printf("sizeof RenderEvent %d\n",sizeof(RenderEvent));

printf("sizeof Part %d\n",sizeof(RenderPart));

printf("sizeof RenderPart %d\n",sizeof(RenderPart));


printf("sizeof Song %d\n",sizeof(Song));

printf("sizeof Track pointer %d\n",sizeof(Track*));


int ta[]={1,2,3,4};
int *tb=new int[4]{1,2,3,4};

printf("array size %d\n",ARRAY_LENGTH(ta));
printf("array size %d\n",ARRAY_LENGTH(tb));

}

int main()
{
	int seed;
dumpSize();
//string structureScript="Modern Song Structure";
string structureScript="Classical Structure Big";
//string structureScript="One Part Simple Structure";
//string structureScript="Random Structure";

//string arrangementScript="Piano Simple Arrangement";
//string arrangementScript="Piano Advanced Swinging Blues";
//string arrangementScript="Piano Advanced Boogie Woogie";
//string arrangementScript="Piano Advanced Disco";
//string arrangementScript="Piano Advanced Classical";
//string arrangementScript="Simple Latin Style Arrangement";
//string arrangementScript="Simple Dance Style Arrangement";
//string arrangementScript="Simple Instrumental March Arrangement";
//string arrangementScript="Simple Ballad Style Arrangement";
//string arrangementScript="Simple Punk Rock Style Arrangement";
string arrangementScript="Random Electro Rock";


//	MidiRt midiWriter(0);
//      MidiFileWriter midiWriter("create_midifile.mid");
     MidiDriver midiWriter;

//seed=3;
seed=134;
//seed=time(NULL);
for(int i=0; i<2;i++) {
    SongCreator *songCreator = new SongCreator();
    songCreator->createSong(seed+i,240,structureScript,arrangementScript,&midiWriter);
    midiWriter.launch();
//    midiWriter.clear();

    delete songCreator;
}
//    songCreator->songToMidi(&midiWriter);


}
