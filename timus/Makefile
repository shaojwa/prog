BINARY=out

CXX = g++
CXXFLAGS = -Wall -O0 -g -std=c++11 -lm
last_source =  $(shell ls -tr | grep \\.cc | tail -1)

$(BINARY): $(last_source)
	$(CXX) $(CXXFLAGS) -o $(BINARY) $(last_source)

.PHONY: run show vim clean 

show:
	@cat $(last_source)

vim:
	vim $(last_source)

clean:
	-rm $(BINARY)

run: $(BINARY)
	cat data.in | ./$(BINARY)    
