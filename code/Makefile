# author wsh @2022
#
CXX = g++
CXXFLAGS = -Wall -O0 --std=c++11 -lpthread

last_source = $(shell ls -tr | grep \\.cc | tail -1)
binary = $(basename $(last_source))
$(info last_source: $(last_source), binary: $(binary))

last:
	$(CXX) $(CXXFLAGS) -o $(binary) $(last_source)

s:
	$(CXX) -S $(last_source)

e:
	$(CXX) -E $(last_source)

v:
	vim $(last_source)

r:
	./$(binary)

help:
	@echo  "make { last | s | e | v | r }"
