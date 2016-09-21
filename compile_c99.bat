@echo off
gcc example_process_producer.c -std=c99 -o producer -w
producer
del producer.exe
PAUSE