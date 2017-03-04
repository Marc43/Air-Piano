air-piano: main.o
    g++ -L./Users/ferranmartinez/Desktop/Air-Piano/lib -lgd -lpng -lz -ljpeg -lfreetype -lm main.o -o heatmap

main.o: main.cc
    g++ -I./libraries/include -c main.cpp
