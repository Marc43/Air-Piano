program.exe: main.o Reproduce_music.o
	g++ -I/Users/ferranmartinez/Desktop/Air-Piano/ libfmod.dylib libfmodL.dylib -o main main.o Reproduce_music.o

Reproduce_music.o:  Reproduce_music.cc Reproduce_music.hh
	g++ -c Reproduce_music.cc

main.o: main.cc
	g++ -c main.cc

clean:
	rm *.o
	rm *.exe
