# Define required macros here
SHELL = /bin/sh
CC = /usr/bin/g++
CFLAGS  = -std=c++11 -O2 -Wall -fdiagnostics-color=always
# CFLAGS  = -std=c++11 -O2 -Wall -fdiagnostics-color=always -g

all: $(patsubst %.cpp, %.out, $(wildcard *.cpp))

%.out: %.cpp Makefile
	$(CC) $(CFLAGS) $< -o $(@:.out=)

clean: $(patsubst %.cpp, %.clean, $(wildcard *.cpp))
	rm -fr $(OBJS) *.dSYM

%.clean:
	rm -f $(@:.clean=)

# .cpp:
# 	$(CC) $(CFLAGS) $@.cpp $(LDFLAGS) -o $@
