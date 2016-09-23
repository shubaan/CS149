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
	PrintProcessList(list);
	
	SortBy(&list, 0);
	printf("\n\n--------------------------------------------------\n\n");
	PrintProcessList(list);
	//FirstCome(list, &runtime);
	//printf("|%-22s|Quanta Used\n|%-.25s|  %.2f\n", "Algorithm", "First Come First Serve", runtime);

	//RoundRobin(list, &runtime);
	//printf("|%-22s|  %.2f\n", "Red Robin", runtime);
}