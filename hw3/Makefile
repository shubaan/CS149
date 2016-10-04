CC=gcc
HDIR=./include
LDIR=./lib
CFLAGS=-I$(HDIR)	-std=c99	-g
makeHW3:	main.o	seller.o	algorithms.o	customer.o	
	$(CC)	$(CFLAGS) $(LDFLAGS)	-o	main	main.o	-lpthread	seller.o	algorithms.o	customer.o
clean:
	rm	-f	*.o	main makeHW3