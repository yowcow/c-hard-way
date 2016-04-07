.PHONY: valgrind clean

all: build/main
	./build/main

valgrind: build/main
	valgrind ./build/main

build/main: build/test.o
	gcc -Wall -fPIC -O2 build/test.o src/main.c -o build/main

build/test.o: src/test.h src/test.cpp
	mkdir -p build && \
	g++ -c -Wall -fPIC -O2 src/test.cpp -o build/test.o

clean:
	-rm -rf build
