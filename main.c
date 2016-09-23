#include <stdio.h>
#include <stdlib.h>
#include "FCFS.h"
#include "RR.h"
#include "process_producer.h"

//TODO: CONGREGATE DEFINE DEFINTIONS IN OWN HEADERFILE

int main(){
	int seed = time(NULL);
	float runtime;
	srand(seed);
	struct process* list;
	CreateProcesses(&list);
	SortProcesses(&list);
	PrintProcessList(list);
	
	FirstCome(list, &runtime);
	printf("|%-22s|Quanta Used\n|%-.25s|  %.2f\n", "Algorithm", "First Come First Serve", runtime);
	printProcessTracker();
	//getFCFSOrder(list, 15);
	printFCFSOrder(list, NUM_PROCESS);

	//RoundRobin(list, &runtime);
	//printf("|%-22s|  %.2f\n", "Round Robin", runtime);
	//printProcessTracker();
	//TO-DO printRoundRobinOrder();

}

void printProcessTracker() {
	for (int i = 0; i < 100; i++) {
		printf("%d ", i);
	}
	printf("\n");
}

void printFCFSOrder(struct process plist[], int size) {
	char *charArray = getFCFSOrder(plist, size);

	for (int i = 0; i < 100; i++) {
		if (charArray[i] == ' ' && i < 10) { // matching
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