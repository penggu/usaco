# Define required macros here
SHELL = /bin/sh
CC = /usr/bin/clang++
CFLAGS  = -Wall -Werror -std=c++11 -fdiagnostics-color=always
# CFLAGS  = -Wall -Werror -std=c++11 -fdiagnostics-color=always -g

all: $(patsubst %.cpp, %.out, $(wildcard *.cpp))

%.out: %.cpp Makefile
	$(CC) $(CFLAGS) $< -o $(@:.out=)

clean: $(patsubst %.cpp, %.clean, $(wildcard *.cpp))
	rm -fr $(OBJS) *.dSYM

%.clean:
	rm -f $(@:.clean=)

# .cpp:
# 	$(CC) $(CFLAGS) $@.cpp $(LDFLAGS) -o $@
