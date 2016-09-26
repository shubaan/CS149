#include <stdio.h>
#include <stdlib.h>
#include "process_producer.h"

#define TRUE 1
#define FALSE 0

void FirstCome(struct process* plist, float* runtime){
	*runtime = (float) MAX_QUANTA;
	int counter = 0;

	while(TRUE){ 
		if(*runtime <= 0){
			*runtime = (*runtime * -1) + (float) MAX_QUANTA; // if the current process goes beyond the maximum time, it is added. for example if process 1 takes 7 seconds and the processes
			break;											//  have been running for 98 seconds, the total runtime will be 100 seconds/quanta
		} 
		else if(counter >= NUM_PROCESS){					//if the counter exceeds the number of processes, exit the loop and return
		*runtime = (float) MAX_QUANTA - *runtime;
			break;
		}
				
		*runtime = *runtime - plist[counter].service_time; // deduct total time from the service time to complete the process
		counter++;
	}
	return;
}

char* getFCFSOrder(struct process** plist, int* size) {

	int numberOfProcessCompleted = 0;
	char *arrayFCFSOrder = malloc(sizeof(char) * CHAR_ARRAYMAX); // Allocate enough to leave spaces for last process to finish 

	*size = 0; 

	int quanta = 0;

	for (int i = 0; i < size; i++) {

		while ((*plist)[i].arrival_time > quanta && (quanta < MAX_QUANTA)) { 
		// Keep looping because the process hasn't arrived
		// A new process cannot start if MAX_QUANTA is already hit
			arrayFCFSOrder[quanta] = ' ';
			quanta++; 
		}

		// After the first while loop, the current process is sure to be starting. This is the actual start time
		// of a process after the waiting of the previous
		(*plist)[i].actual_start_time = quanta;
		while (((*plist)[i].service_time  > 0)) { 
			arrayFCFSOrder[quanta] = (*plist)[i].name;
			quanta++;
			(*plist)[i].service_time = (*plist)[i].service_time - 1; // Decrement a service time each time it's been added to array of process done array (arrayFCFS)
		}

		// Actual end time after service time is finished
		(*plist)[i].end_time = quanta - 1;

		*size += 1;

		if (quanta > MAX_QUANTA - 1) {
			break;
		}
	}
	return arrayFCFSOrder;
}



