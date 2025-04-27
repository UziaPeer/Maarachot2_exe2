# Email: peeruzia@gmail.com
CXX = g++
CXXFLAGS = -Iinclude -std=c++11

SRC = src/SquareMat.cpp src/Queue.cpp
MAIN = main.cpp
TEST = test/test.cpp

all: Main

Main: $(MAIN) $(SRC)
	$(CXX) $(CXXFLAGS) -o Main $(MAIN) $(SRC)

test: test_exec

test_exec: $(TEST) $(SRC)
	$(CXX) $(CXXFLAGS) -o test_exec $(TEST) $(SRC)

valgrind: Main
	valgrind ./Main

clean:
	rm -f Main test_exec

.PHONY: all Main test test_exec valgrind clean
