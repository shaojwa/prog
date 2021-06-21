
CXX = g++
CXXFLAGS = -Wall -O0 -g --std=c++11
BINARY = out
last_source = $(shell ls -tr | grep \\.cc | tail -1)

last:
	$(CXX) $(CXXFLAGS) -o $(BINARY) $(last_source)

run:
	./out

