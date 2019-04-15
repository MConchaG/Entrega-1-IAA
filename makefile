main.o: src/main.cpp
	g++ -c src/main.cpp -Wall
instanceConstructor.o: src/instanceConstructor.cpp src/instanceConstructor.h
	g++ -c src/instanceConstructor.cpp -Wall

nsp: main.o instanceConstructor.o
	g++ main.o instanceConstructor.o -o nsp

clean :
	rm nsp main.o instanceConstructor.o
