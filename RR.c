#include <stdio.h>
#include <stdlib.h>
#include "process_producer.h"
#define TRUE 1 //add header to store define variables

void RoundRobin(struct process* o_plist, float* runtime){ //original plist. Gonna use copy so the arrays can be modified in the funciton
	int counter = 0;
	int incomplete_process = NUM_PROCESS;
//ADD TEST IF MAX_QUANTA LESS THAN NUM_PROCESS
	struct process* plist = malloc(sizeof(struct process) * NUM_PROCESS);
	float servicetime;
	memcpy(plist, o_plist, (sizeof(struct process) * NUM_PROCESS));
	while(TRUE){
		if(incomplete_process <= 0) break;
		servicetime = plist[counter % NUM_PROCESS].service_time;
		if(servicetime <= 1.0 && servicetime > 0.0){
			*runtime += servicetime;
			plist[counter % NUM_PROCESS].service_time = 0;
			incomplete_process -= 1;
		} 
		else{
			*runtime += 1;
			plist[counter % NUM_PROCESS].service_time -= 1.0;
		} 
		counter++;
	}
	free(plist);
	return;
}