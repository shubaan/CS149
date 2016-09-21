#include <stdio.h>
#include <stdlib.h>
#include "process_producer.h"
#include "FCFS.h"

int main(){
	int seed = time(NULL);
	float runtime;
	srand(seed);
	struct process* list;
	CreateProcesses(&list);
	PrintProcessList(list);
	
	FCFS(list, &runtime);
	printf("|%-22s|Quanta Used\n|%-.25s|  %.2f\n", "Algorithm", "First Come First Serve", runtime);
}