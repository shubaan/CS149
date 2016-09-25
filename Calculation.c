#include <stdio.h>
#include <stdlib.h>
#include "process_producer.h"
#include "Calculation.h"

float calAverageTurnaround(struct process plist[], int size) {	
	float turnaroundTime = 0.0;

	for (int i = 0; i < size; i++) {
		// Turn around time is the time from the arrival to end of a process
		turnaroundTime += plist[i].end_time - plist[i].arrival_time;
	}
	return (turnaroundTime / size);
}

float calAverageWaiting(struct process plist[], int size) {
	float avgWaiting = 0.0;

	for (int i = 0; i < size; i++) {
		// Waiting time is the time to wait to start
		avgWaiting += plist[i].actual_start_time - plist[i].arrival_time;
	}
	return (avgWaiting / size);
}

float calAverageResponse(struct process plist[], int size) {
	float responseTime = 0.0;

	for (int i = 0; i < size; i++) {
		// Response time is the actual starting time to when the first output is produced
		responseTime += plist[i].end_time - plist[i].actual_start_time;
	}
	return (responseTime / size);
}

int calThroughput(char charArray[], int size) {
	// Only processes that are completed before the [0-99] quanta range are counted.
	int throughput = size;
	
	if (charArray[100] != NULL) {
		// One process was still running after [0-99] quanta
		throughput = size - 1;
	} else {
		throughput = size;
	}

	return throughput;
}
