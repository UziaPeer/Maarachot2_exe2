CXX = g++
CXXFLAGS = -Iinclude -std=c++11

SRC = src/SquareMat.cpp src/Queue.cpp
MAIN = main.cpp

all: Main

Main: $(MAIN) $(SRC)
	$(CXX) $(CXXFLAGS) -o Main $(MAIN) $(SRC)

valgrind: Main
	valgrind ./Main

clean:
	rm -f Main