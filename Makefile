CC=gcc
CFLAGS=-I.	-std=c99	-w
makeHW2:	process_producer.o	main.o FCFS.o
	$(CC)	$(CCFLAGS)	-o	producer process_producer.o	main.o	FCFS.o

clean:
	rm	-f	*.o	makeHW2