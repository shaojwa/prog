BINARY=out

CXX = g++
CXXFLAGS = -Wall -O0 -g -std=c++11 -lpthread
PTHFLAGS = -DUSE_SPINLOCK

#last_source =  $(shell ls -tr | grep \\.cc | tail -1)

objects = main.o advio.o pth.o

last: $(objects)
	$(CXX) $(CXXFLAGS) -o $(BINARY) $(objects)


main.o: main.cc
	$(CXX) -c main.cc
	

advio.o: advio.cc
	$(CXX) -c advio.cc


pth.o: pth.cc
	$(CXX) $(PTHFLAGS) -c pth.cc

clean:
	rm $(objects) $(BINARY)

run:
	./$(BINARY)    
