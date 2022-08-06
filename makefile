all: compile run

compile:
	g++ -I ./include/ -o ./lib/Arraylist.o -c ./src/ArrayList.cpp
	g++ -I ./include/ -o ./lib/factorial.o -c ./src/Factorial.cpp
	g++ -I ./include/ -o ./bin/main ./lib/Arraylist.o ./lib/factorial.o  ./src/main.cpp

run:
	./bin/main