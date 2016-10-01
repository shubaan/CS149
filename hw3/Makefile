CC=gcc
HDIR=./include
LDIR=./lib
CFLAGS=-I$(HDIR)	-std=c99
LDFLAGS=
makeHW3:	main.o
	$(CC)	$(CFLAGS) $(LDFLAGS)	-o	main main.o	-lpthread
clean:
	rm	-f	*.o	main makeHW3