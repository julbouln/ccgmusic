SRCS=$(wildcard src/*.cpp) $(wildcard src/*/*.cpp)
OBJS=$(SRCS:.cpp=.o)

#CFLAGS_OPT=-O2 -ffast-math -fsingle-precision-constant
CFLAGS_OPT=-g -Wall
CFLAGS=$(CFLAGS_OPT) -I src/ -I src/structuregenerators/ -I src/rythmgenerators/ -I src/renderers/ -I src/melodycreators/ -I src/ornamentors/ -I src/innerstructuregenerators/ -I src/arrangers/ -I src/harmonygenerators/

all: $(OBJS)
	g++ $(CFLAGS) -DTARGET_PLATFORM_LINUX=1 -DTARGET_PLATFORM_LINUX_I386=1 -DTARGET_PLATFORM_LINUX_X86_64=1 -DTARGET_PLATFORM_POSIX=1 -I/usr/include/jdksmidi \
	ccgmusic.cpp -c -o ccgmusic.o
	g++ $(CFLAGS) -Wall $? ccgmusic.o -lrtmidi -ljdksmidi -o ccgmusic

src/MidiFileWriter.o: src/MidiFileWriter.cpp
	g++ $(CFLAGS) -DTARGET_PLATFORM_LINUX=1 -DTARGET_PLATFORM_LINUX_I386=1 -DTARGET_PLATFORM_LINUX_X86_64=1 -DTARGET_PLATFORM_POSIX=1 -I/usr/include/jdksmidi $< -c -o $@

src/MidiRt.o: src/MidiRt.cpp
	g++ $(CFLAGS) -I /usr/local/include $< -c -o $@

%.o: %.cpp
	g++ $(CFLAGS) $< -c -o $@

test: $(OBJS)
	g++ $(CFLAGS) -DTARGET_PLATFORM_LINUX=1 -DTARGET_PLATFORM_LINUX_I386=1 -DTARGET_PLATFORM_LINUX_X86_64=1 -DTARGET_PLATFORM_POSIX=1 -I/usr/include/jdksmidi \
	test.cpp -c -o test.o
	g++ $(CFLAGS) -Wall $(OBJS) test.o -lrtmidi -ljdksmidi -o test

clean:
	rm *.o
	rm */*.o
	rm */*/*.o
	rm ccgmusic
	rm test
	rm massif.out
	rm massif.log

massif: test
	valgrind --tool=massif  --heap-admin=1 --depth=50 --peak-inaccuracy=0.0 --detailed-freq=1 --threshold=0.0 --time-unit=B --massif-out-file=massif.out ./test
	ms_print massif.out > massif.log

callgrind: test
	valgrind --tool=callgrind --callgrind-out-file=callgrind.out ./test
