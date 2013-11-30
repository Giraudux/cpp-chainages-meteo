all: ./build/tp3

./build/tp3: ./build/main.o ./build/Chainage.o ./build/DateMeteo.o ./build/ReleveMeteo.o
	g++ -o ./build/tp3 ./build/main.o ./build/Chainage.o ./build/DateMeteo.o ./build/ReleveMeteo.o

./build/Chainage.o: ./src/Chainage.cpp
	g++ -o ./build/Chainage.o -c ./src/Chainage.cpp

./build/DateMeteo.o: ./src/DateMeteo.cpp
	g++ -o ./build/DateMeteo.o -c ./src/DateMeteo.cpp

./build/ReleveMeteo.o: ./src/ReleveMeteo.cpp
	g++ -o ./build/ReleveMeteo.o -c ./src/ReleveMeteo.cpp

./build/main.o: ./src/main.cpp
	g++ -o ./build/main.o -c ./src/main.cpp

clean:
	rm -f ./build/*
