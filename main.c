#include <stdio.h>
#include <stdlib.h>
#include "process_producer.h"


int main(){
	int seed = time(NULL);
	srand(seed);
	struct process* list;
	CreateProcesses(&list);
	PrintProcessList(list);
}