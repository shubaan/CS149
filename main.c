#include <stdio.h>
#include <stdlib.h>
#include "FCFS.h"
#include "RR.h"
#include "process_producer.h"
#include "Sorter.h"
#include "Calculation.h"
//TODO: CONGREGATE DEFINE DEFINTIONS IN OWN HEADERFILE

void printProcessTracker();
void printFCFSOrder(struct process** plist, int size);

int main(){
	int seed = time(NULL);
	float runtime;
	srand(seed);
	struct process* list;
	CreateProcesses(&list);
	PrintProcessList(list);
	SortBy(&list, 0); //The input num decides what field to sort by 0 - arrival time; 1 - service time; 2 - priority; 3 - actual arrival time; 4 - end time
	printProcessTracker();
	printFCFSOrder(list, NUM_PROCESS);
	return 1;
}

/*
* Blueprint to track where each process is during the 100 quatum time frame
* Can tell some processes don't start at arrival time because another process is still running
*/
void printProcessTracker() {
	printf("\nProcess Tracker (Hold control key and hit - key to zoom out in terminal to see)\n"); // need a more elegant solution than this
	for (int i = 0; i < MAX_QUANTA; i++) {
		printf("%d ", i);
	}
	printf("\n");
}


void printFCFSOrder(struct process** plist, int size) {

	char* charArray = getFCFSOrder(&plist, &size);

	// Adjust to add extra spaces to match printProcessTracker();
	// Char array doesn't have extra spaces to accommodate the difference
	for (int i = 0; i < CHAR_ARRAYMAX; i++) {
		if (charArray[i] == ' ' && i < 10) { 
			printf("  ");
		} else if (charArray[i] == ' ' && i >= 10) {
			printf("   ");
		} else if (i < 10) {
			printf("%c ", charArray[i]);
		} else {
			printf("%c  ", charArray[i]);
		}
	}
	printf("\n");
	// Size is now the # of processes that completed its process 
	printf("Average response time: %.2f\n", calAverageResponse(plist, size));
	printf("Average waiting time: %.2f\n", calAverageWaiting(plist, size));
	printf("Average turnaround time: %.2f\n", calAverageTurnaround(plist, size));
	printf("Throughput: %d\n", calThroughput(charArray, size));

	free(charArray);
}
