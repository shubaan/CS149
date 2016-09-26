#include <stdio.h>
#include <stdlib.h>
#include "process_producer.h"
#include "Sorter.h"

#define TRUE 1 //add header to store define variables

void RoundRobin(struct process* o_plist){ //original plist. Gonna use copy so the arrays can be modified in the funciton
	int counter_char_array = 0;
	int counter_process = 0;
	int quanta;
//ADD TEST IF MAX_QUANTA LESS THAN NUM_PROCESS
	struct process* plist = malloc(sizeof(struct process) * NUM_PROCESS);
	memcpy(plist, o_plist, (sizeof(struct process) * NUM_PROCESS));

	SortBy(&plist, 0); // in case not sorted by arrival time
	quanta = plist[0].arrival_time; //Set time to when first proces arrives
	char* rr_process_order = malloc(sizeof(char) * CHAR_ARRAYMAX);

	while(counter_char_array < quanta){
		rr_process_order[counter_char_array] = ' ';
		counter_char_array++;
	}

	// NEED TO ACCOUNT FOR IDLE CPU
	while(TRUE){ 
		if(quanta >= MAX_QUANTA) break;
		else if(plist[counter_process % NUM_PROCESS].service_time == 0 || plist[counter_process % NUM_PROCESS].arrival_time > quanta) counter_process++; // cheap way to pretend process isn't in queue anymore, just skip over it, no time taken
		else if(plist[counter_process % NUM_PROCESS].service_time < 1){ // because service time is a float, we need a special case to reduce it to exactly 0
			plist[counter_process % NUM_PROCESS].service_time = 0;
			rr_process_order[counter_char_array] = plist[counter_process % NUM_PROCESS].name;
			counter_process++;
			counter_char_array++;
			quanta++;
		}
		else {
			plist[counter_process % NUM_PROCESS].service_time - 1;
			rr_process_order[counter_char_array] = plist[counter_process % NUM_PROCESS].name;
			counter_char_array++; // always 1 timeslice per process
			counter_process++;
			quanta++;
		}
	}

	for(int x = 0; x < MAX_QUANTA; x++){
		printf("%d ", x);
	}

	printf("\n");

	for(int x = 0; x < CHAR_ARRAYMAX; x++){
		printf("%c ", plist[x].name);
	}

	free(plist);
	free(rr_process_order);
	return;
}