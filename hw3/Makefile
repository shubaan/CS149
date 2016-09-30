CC=gcc
HDIR=./include
LDIR=./lib
CFLAGS=-I$(HDIR)	-std=c99
LDFLAGS=-L$(LDIR)	-static
makeHW3:	main.o
	$(CC)	$(CCFLAGS) $(LDFLAGS)	-o	hw3 main.o	
clean:
	rm	-f	*.o	makeHW3