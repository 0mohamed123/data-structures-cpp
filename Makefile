CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I include

all: main

main: src/main.cpp
	$(CXX) $(CXXFLAGS) -o main src/main.cpp

test: tests/test_all.cpp
	$(CXX) $(CXXFLAGS) -o test_runner tests/test_all.cpp
	./test_runner

clean:
	rm -f main test_runner *.exe
