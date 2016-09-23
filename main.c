#include <stdio.h>
#include <stdlib.h>
#include "FCFS.h"
#include "RR.h"
#include "process_producer.h"
#include "Sorter.h"
//TODO: CONGREGATE DEFINE DEFINTIONS IN OWN HEADERFILE

int main(){
	int seed = time(NULL);
	float runtime;
	srand(seed);
	struct process* list;
	CreateProcesses(&list);
	SortProcesses(&list);
	PrintProcessList(list);

	printProcessTracker();
	printFCFSOrder(list, NUM_PROCESS);
	//SortBy(&list, 0);
	//PrintProcessList(list);
}

/*
* Blueprint to track where each process is during the 100 quatum time frame
* Can tell some processes don't start at arrival time because another process is still running
*/
void printProcessTracker() {
	for (int i = 0; i < 100; i++) {
		printf("%d ", i);
	}
	printf("\n");
}


void printFCFSOrder(struct process plist[], int size) {
	char *charArray = getFCFSOrder(plist, size);

	// Adjust to add extra spaces to match printProcessTracker();
	// Char array doesn't have extra spaces to accommodate the difference
	for (int i = 0; i < 100; i++) {
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

	free(charArray);
}