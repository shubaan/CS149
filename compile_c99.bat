@echo off
gcc process_producer.c -std=c99 -o producer -w
producer
del producer.exe
PAUSE