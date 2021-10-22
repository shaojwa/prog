
CXX = g++
CXXFLAGS = -Wall -O0 -g --std=c++11 -lpthread
BINARY = out
last_source = $(shell ls -tr | grep \\.cc | tail -1)

last:
	$(CXX) $(CXXFLAGS) -o $(BINARY) $(last_source)

s:
	$(CXX) -S $(last_source)

e:
	$(CXX) -E $(last_source)

v:
	vim $(last_source)

r:
	./out

