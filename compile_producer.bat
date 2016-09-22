gcc -std=c99 -I./include main.c process_producer.c RR.c FCFS.c -o producer -w
producer.exe
PAUSE
del producer.exe