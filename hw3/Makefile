CC=gcc
HDIR=./include
LDIR=./lib
CFLAGS=-I$(HDIR)	-std=c99
LDFLAGS=
makeHW3:	example_lock.o
	$(CC)	$(CFLAGS) $(LDFLAGS)	-o	example_lock example_lock.o	-lpthread
clean:
	rm	-f	*.o	makeHW3