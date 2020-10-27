RUN_MAIN := src/main.cpp
SOURCES := $(filter-out $(RUN_MAIN), $(wildcard src/*.cpp))

all: test run

main.o: src/main.cpp src/shell.h
	gcc $(SOURCES) src/main.cpp -lstdc++ -std=c++17 -o main.out

run: main.o
	./main.out

tests.o: tests/main.cpp src/shell.h
	gcc $(SOURCES) tests/main.cpp -lstdc++ -std=c++17 -o test.out

exeTests.o: tests/extest.cpp tests/pipetest.cpp
	gcc tests/extest.cpp -lstdc++ -std=c++17 -o tests/extest
	gcc tests/pipetest.cpp -lstdc++ -std=c++17 -o tests/pipetest

test: exeTests.o tests.o
	./test.out

build: main.o exeTests.o tests.o