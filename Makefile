all: ./build/tp3

./build/tp3: ./build/main.o ./build/Chainage.o ./build/Date.o ./build/Releve.o
	g++ -o ./build/tp3 ./build/main.o ./build/Chainage.o ./build/Date.o ./build/Releve.o

./build/Chainage.o: ./src/Chainage.cpp
	g++ -o ./build/Chainage.o -c ./src/Chainage.cpp

./build/Date.o: ./src/Date.cpp
	g++ -o ./build/Date.o -c ./src/Date.cpp

./build/Releve.o: ./src/Releve.cpp ./src/Date.h
	g++ -o ./build/Releve.o -c ./src/Releve.cpp

./build/main.o: ./src/main.cpp
	g++ -o ./build/main.o -c ./src/main.cpp

clean:
	rm -r ./build/*
