tank: cs.o fg.o lodepng.o
	g++ -std=c++11 -pthread -o ../tank ./lib/coreSystems.o ./lib/fgetter.o ./lodepng/lodepng.o

cs.o: coreSystems.cpp coreSystems.h
	g++ -std=c++11 -pthread -c coreSystems.cpp -o ./lib/coreSystems.o

fg.o: fgetter.cpp fgetter.h
	g++ -std=c++11 -pthread -c fgetter.cpp -o ./lib/fgetter.o

lodepng.o: ./lodepng/lodepng.cpp ./lodepng/lodepng.h
	g++ -std=c++11 -pthread -c ./lodepng/lodepng.cpp -o ./lodepng/lodepng.o

clean:
	rm ./lib/*.o
