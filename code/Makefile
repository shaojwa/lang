CXX = g++
CXXFLAGS = -Wall -O0 -g --std=c++11 -lpthread
BINARY = out
last_source = $(shell ls -tr | grep \\.cc | tail -1)

last:
	$(CXX) $(CXXFLAGS) -o $(BINARY) $(last_source)

asm:
	$(CXX) -S $(last_source)

pre:
	$(CXX) -E $(last_source)

vim:
	vim $(last_source)

run:
	@./out

help:
	@echo  "make { last | asm | pre | vim | run }"
