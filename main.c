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
	
	runtime = FCFS(list);
	printf("First Come First Server: %.2f\n", runtime);
}