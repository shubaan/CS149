CC=gcc
HDIR=./include
LDIR=./lib
CFLAGS=-I$(HDIR)	-std=c99	-DHAVE_STRUCT_TIMESPEC
LDFLAGS=-L$(LDIR)	-static	
makeHW3:	example_lock.o
	$(CC)	$(CFLAGS) $(LDFLAGS)	-o	example_lock example_lock.o	-lpthreadGCE2
clean:
	rm	-f	*.o	makeHW3