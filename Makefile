CXX = g++

FLAGS = -Wall -Werror

CFLAGS = -c -Wall -Werror

OBJECTS = build/src/main.o build/src/alphabet_generation.o build/src/password_generation.o

OBJECTS_TEST = build/test/main.o build/test/tests.o build/src/alphabet_generation.o build/src/password_generation.o

.PHONY: all bin build clean test

all: build bin bin/main test

test: build bin bin/main_test
	bin/main_test

bin/main_test: $(OBJECTS_TEST)
	$(CXX) $(FLAGS) $(OBJECTS_TEST) -o bin/main_test

build/test/main.o: test/main.cpp
	$(CXX) $(CFLAGS) test/main.cpp -I thirdparty/ -I src/ -o build/test/main.o

build/test/tests.o: test/tests.cpp
	$(CXX) $(CFLAGS) test/tests.cpp -I thirdparty/ -I src/ -o build/test/tests.o

bin/main: $(OBJECTS)
	$(CXX) $(FLAGS) $(OBJECTS) -o bin/main

build/src/main.o: src/main.cpp
	$(CXX) $(CFLAGS) src/main.cpp -o build/src/main.o

build/src/alphabet_generation.o: src/alphabet_generation.cpp
	$(CXX) $(CFLAGS) src/alphabet_generation.cpp -o build/src/alphabet_generation.o

build/src/password_generation.o: src/password_generation.cpp
	$(CXX) $(CFLAGS) src/password_generation.cpp -o build/src/password_generation.o

build:
	mkdir -p build/src
	mkdir -p build/test

bin:
	mkdir -p bin 

clean:
	-rm -rf build bin