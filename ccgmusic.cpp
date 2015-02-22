#include <signal.h>
#include "CcgMusic.h"
#include "MidiFileWriter.h"
#include "MidiRt.h"

char *getCmdOption(char **begin, char **end, const std::string &option)
{
    char **itr = std::find(begin, end, option);
    if (itr != end && ++itr != end)
    {
        return *itr;
    }
    return 0;
}

bool cmdOptionExists(char **begin, char **end, const std::string &option)
{
    return std::find(begin, end, option) != end;
}

int main(int argc, char *argv[])
{
    int seed = time(NULL);
    int tempo = 120;
    int port = 0;
    string driver="file";
    string structureScript = "One Part Simple Structure";
    string arrangementScript = "Piano Simple Arrangement";
    string outputFile = "output.mid";

    SongCreator *songCreator = new SongCreator();


    if (cmdOptionExists(argv, argv + argc, "--help") || cmdOptionExists(argv, argv + argc, "-h"))
    {
        printf("Usage: ccgmusic [options]\n");
        printf("Options:\n");
        printf("\t--seed SEED\t\tSeed for initialize randomizer\n\t\t\t\tDefault to current time\n");
        printf("\t--tempo TEMP\t\tTempo for generated song\n\t\t\t\tDefault to 120\n");
        printf("\t--structure \"name\"\tStructure of the song\n\t\t\t\tDefault to \"One Part Simple Structure\"\n\t\t\t\tSet list to shown available structures\n");
        printf("\t--arranger \"name\"\tArranger of the song\n\t\t\t\tDefault to \"Piano Simple Arrangement\"\n\t\t\t\tSet list to shown available structures\n");
        printf("\t--driver DRIVER\t\tDriver for render song (file or rt)\n\t\t\t\tDefault to file\n");
        printf("\t--filename FILE\t\tOutput filename (file driver)\n\t\t\t\tDefault to output.mid\n");
        printf("\t--port PORT\t\tMidi output port (rt driver)\n\t\t\t\tDefault to 0\n");

        printf("Description: ccgmusic command line utility\n");
        return 0;
    }
    

    if (cmdOptionExists(argv, argv + argc, "--seed"))
    {
        seed = atoi(getCmdOption(argv, argv + argc, "--seed"));
    }

    if (cmdOptionExists(argv, argv + argc, "--tempo"))
    {
        tempo = atoi(getCmdOption(argv, argv + argc, "--tempo"));
    }

    if (cmdOptionExists(argv, argv + argc, "--structure"))
    {
        structureScript = getCmdOption(argv, argv + argc, "--structure");
        if(songCreator->structures.count(structureScript)==0)
        {
            printf("Available structures:\n");
            for (map<string, SongCreator::StructureGeneratorCreator>::iterator it = songCreator->structures.begin(); it != songCreator->structures.end(); ++it)
                printf("\t\"%s\"\n",it->first.c_str());
            return 0;
        }
    }

    if (cmdOptionExists(argv, argv + argc, "--arranger"))
    {
        arrangementScript = getCmdOption(argv, argv + argc, "--arranger");
        if(songCreator->arrangers.count(arrangementScript)==0)
        {
            printf("Available arrangers:\n");
            for (map<string, SongCreator::ArrangerCreator>::iterator it = songCreator->arrangers.begin(); it != songCreator->arrangers.end(); ++it)
                printf("\t\"%s\"\n",it->first.c_str());
            return 0;
        }
    }

    if (cmdOptionExists(argv, argv + argc, "--driver"))
    {
        driver = getCmdOption(argv, argv + argc, "--driver");
    }

    if (cmdOptionExists(argv, argv + argc, "--filename"))
    {
        outputFile = getCmdOption(argv, argv + argc, "--filename");
    }

    if (cmdOptionExists(argv, argv + argc, "--port"))
    {
        port = atoi(getCmdOption(argv, argv + argc, "--port"));
    }

    printf("Using seed: %d, tempo: %d, structure: \"%s\", arrangement: \"%s\", driver: %s\n",seed,tempo,structureScript.c_str(),arrangementScript.c_str(),driver.c_str());

    if(driver=="file") {
        MidiFileWriter midiWriter(outputFile);
        songCreator->createSong(seed, tempo, structureScript, arrangementScript, &midiWriter);
    }

    if(driver=="rt") {

        MidiRt midiWriter(port);
//        void sig(int s) {
//            midiWriter.finish();
//        }
//    signal (SIGINT,&sig);

        songCreator->createSong(seed, tempo, structureScript, arrangementScript, &midiWriter);
    }

    delete songCreator;
    

    return 0;
}