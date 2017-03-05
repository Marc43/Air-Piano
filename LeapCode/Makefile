all: LeeMotion.o AirPiano Reproduce_music.o

OS := $(shell uname)
ARCH := $(shell uname -m)

ifeq ($(OS), Linux)
  ifeq ($(ARCH), x86_64)
    LEAP_LIBRARY := ../LeapSDK/lib/x64/libLeap.so -Wl,-rpath,../LeapSDK/lib/x64
  else
    LEAP_LIBRARY := ../LeapSDK/lib/x86/libLeap.so -Wl,-rpath,../LeapSDK/lib/x86
  endif
else
  # OS X
  LEAP_LIBRARY := ../LeapSDK/lib/libLeap.dylib
endif

LeeMotion.o: LeeMotion.cc LeeMotion.hh
	$(CXX) -Wall -g -I../LeapSDK/include LeeMotion.cc LeeMotion.hh -c $(LEAP_LIBRARY)
ifeq ($(OS), Darwin)
	install_name_tool -change @loader_path/libLeap.dylib ../LeapSDK/lib/libLeap.dylib
endif

AirPiano: AirPiano.cc LeeMotion.o Reproduce_music.o
	$(CXX) -Wall -g -I../LeapSDK/include -I/Users/ferranmartinez/Desktop/Air-Piano/ libfmod.dylib libfmodL.dylib  AirPiano.cc LeeMotion.o Reproduce_music.o -o AirPiano $(LEAP_LIBRARY)
ifeq ($(OS), Darwin)
	install_name_tool -change @loader_path/libLeap.dylib ../LeapSDK/lib/libLeap.dylib AirPiano
endif

Reproduce_music.o:  Reproduce_music.cc Reproduce_music.hh
	g++ -c Reproduce_music.cc

clean:
	rm -rf AirPiano AirPiano.dSYM *.o
