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