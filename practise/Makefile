BINARY=out

CXX = g++
CXXFLAGS = -Wall -O0 -g -std=c++11 -lpthread
PTHFLAGS = -DUSE_SPINLOCK

#last_source =  $(shell ls -tr | grep \\.cc | tail -1)

objects = main.o advio.o pth.o times.o compile.o cppl.o

$(BINARY): $(objects)
	$(CXX) $(CXXFLAGS) -o $(BINARY) $(objects)


main.o: main.cc
	$(CXX) $(CXXFLAGS) -c main.cc
	

advio.o: advio.cc advio.h
	$(CXX) -c advio.cc


pth.o: pth.cc pth.h
	$(CXX) $(PTHFLAGS) -c pth.cc

tm.o: tm.cc tm.h
	$(CXX) $(CXXFLAGS) -c tm.cc


compile.o: compile.cc compile.h
	$(CXX) $(CXXFLAGS) -O0 -c compile.cc

cppl.o: cppl.cc cppl.h
	$(CXX) $(CXXFLAGS) -O0 -c cppl.cc

.PHONY: clean run
clean:
	rm $(objects) $(BINARY)

run: $(BINARY)
	./$(BINARY)    
