.PHONY: default help object executable all clean segfault dynamic static nobugs
CC = gcc
CFLAGS0	= -g -O0
CFLAGS1 = -O1
CFLAGS2 = -O2

LD = $(CC)
LDFLAGS = -lm

SOURCE_C = $(wildcard *.c)
OBJECTS_C = $(patsubst %.c, %_c.o, $(SOURCE_C))
EXECUTABLES = $(patsubst %.c, %.e, $(SOURCE_C))

default: all

help:
	@echo "\
Options:\n\n\
  make all:           make every executable (default)\n\
	make object-fpe:    create object of fpe\n\
  make profile1:          example 1\n\
  make profile2:          example 2\n\
  make clean:         delete output files\n\
  make help:          display this help"

objects: $(OBJECTS_C)

executable: $(EXECUTABLES)

all: objects executable

profile1: profile_me_1.e

profile2: profile_me_2.e


# Choose one or the other if want to have ERROR EXCEPTIONS
%_c.o: %.c
	$(CC) $(CFLAGS2) -pg -c $^ -o $@


%.e: %_c.o
	$(LD) $^ $(LDFLAGS) -pg -o $@

clean:
	rm -rfv $(OBJECTS_C) $(EXECUTABLES)
