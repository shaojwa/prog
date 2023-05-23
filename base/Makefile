BINARY=out

CXX = g++
CXXFLAGS = -Wall -O0 -g -std=c++11 -lpthread
PTHFLAGS = -DUSE_SPINLOCK

last_source =  $(shell ls -tr | grep \\.cc | tail -1)
#objects = $(last_source)

objects = main.o advio.o pth.o lck.o times.o compile.o cppl.o

.PHONE:
build: $(objects)
#	$(CXX) $(CXXFLAGS) -L. -lwshlk -o $(BINARY) $(objects)
	$(CXX) $(CXXFLAGS) -o $(BINARY) $(objects)

wshlk:
	$(CXX) $(CXXFLAGS) --shared -o libwshlk.so wshlk.cc

main.o: main.cc
	$(CXX) $(CXXFLAGS) -c main.cc

advio.o: advio.cc
	$(CXX) -c $<


pth.o: pth.cc
	$(CXX) $(CXXFLAGS) $(PTHFLAGS) -c $<

lck.o: lck.cc
	$(CXX) $(CXXFLAGS) $(PTHFLAGS) -c $<


tm.o: tm.cc
	$(CXX) $(CXXFLAGS) -c tm.cc


compile.o: compile.cc
	$(CXX) $(CXXFLAGS) -c compile.cc

cppl.o: cppl.cc
	$(CXX) $(CXXFLAGS) -O0 -c $<


.PHONY: clean run
clean:
	rm $(objects) $(BINARY)


run: $(BINARY)
	./$(BINARY)
