.PHONY: default help object executable all clean segfault dynamic static nobugs
CC = gcc

CFLAGS = -g -O0 -lm
CFLAGS2 = -g -O0 -lm -DTRAPFPE

LD = $(CC)

LDFLAGS = -lm

SOURCE_C = $(wildcard *.c)
OBJECTS_C = $(patsubst %.c, %_c.o, $(SOURCE_C))
EXECUTABLES = $(patsubst %.c, %.e, $(SOURCE_C))

SOURCE_fpe = $(wildcard fpe_x87_sse/*.c)
fpe_OBJECT = $(patsubst %.c, %_c.o, $(SOURCE_fpe))

default: all

help:
	@echo "\
Options:\n\n\
  make all:           make every executable (default)\n\
	make object-fpe:    create object of fpe\n\
  make fpe1:          example 1\n\
  make fpe2:          example 2\n\
  make fpe3:          example 3\n\
  make clean:         delete output files\n\
  make help:          display this help"

objects: $(OBJECTS_C)

executable: $(EXECUTABLES)

all: objects executable

object-fpe: $(fpe_OBJECT)

fpe1: test_fpe1.e

fpe2: test_fpe2.e

fpe3: test_fpe3.e



fpe_x87_sse/%_c.o: fpe_x87_sse/%.c
	$(CC) $(CFLAGS) -c $^ -o $@

# Choose one or the other if want to have ERROR EXCEPTIONS
%_c.o: %.c
	#$(CC) $(CFLAGS) -c $^ -o $@
	$(CC) $(CFLAGS2) -c $^ -o $@

%.e: %_c.o
	#$(LD) $^ -o $@ $(LDFLAGS)
	$(LD) -v fpe_x87_sse/fpe_x87_sse_c.o $^ $(LDFLAGS) -o $@

clean:
	rm -rfv $(OBJECTS_C) $(EXECUTABLES)
