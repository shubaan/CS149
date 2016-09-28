#include <stdio.h>
#include <stdlib.h>
#include "process_producer.h"
#include "Sorter.h"

#define TRUE 1 //add header to store define variables

void RoundRobin(struct process* o_plist){ //original plist. Gonna use copy so the arrays can be modified in the funciton
	int counter_char_array = 0;
	int counter_process = 0;
	int queue[NUM_PROCESS] = {0};
	int available_service = 0;
	int quanta;
	int head = 0; //start at beginning
	char* rr_process_order = malloc(sizeof(char) * CHAR_ARRAYMAX);
//ADD TEST IF MAX_QUANTA LESS THAN NUM_PROCESS
	struct process* plist = malloc(sizeof(struct process) * NUM_PROCESS);
	memcpy(plist, o_plist, sizeof(struct process) * NUM_PROCESS);

	printf("---------------------------------------\n");

	SortBy(&plist, 0); // in case not sorted by arrival time
	quanta = plist[0].arrival_time; //Set time to when first proces arrives
	PrintProcessList(o_plist);

	while(counter_char_array < quanta){
		rr_process_order[counter_char_array] = ' ';
		counter_char_array++;
	}

	while(TRUE){ 
		if(quanta >= MAX_QUANTA) break;
		//Checks how many processes are currently in queued, if there is a 1 in the array slot, there is process that has both arrived and has positive service time - can change to do so it always runs once
		for(int x = 0; x < NUM_PROCESS; x++){
			if(plist[(x + head) % NUM_PROCESS].service_time == 0) queue[x] = 0;
			else if(plist[(x + head) % NUM_PROCESS].service_time > 0 && plist[(x + head) % NUM_PROCESS].arrival_time <= quanta){
				queue[(x + head) % NUM_PROCESS] = 1;
				available_service = 1;
				head = (x + head) % NUM_PROCESS;
				break;
			}
			else queue[x] = 0;
		}

		// just for testing purposes
		//for(int x = 0; x < NUM_PROCESS; x++){
		//	printf("%d  ", queue[x]);
		//}
		//printf("\n");
		//

		if(available_service == 0){
			//available_service = 0; not needed
			rr_process_order[counter_char_array] = ' ';
			counter_char_array++;
		}
		else if(queue[head] == 1){
			if(plist[head].service_time < 1) plist[head].service_time = 0;
			else plist[head].service_time -= 1;
			rr_process_order[counter_char_array] = plist[head].name;
			counter_char_array++;
		}
		quanta++;
		head = (head + 1) % NUM_PROCESS;
	}

	// print all quanta slices
	printf("\n");
	for(int x = 0; x < MAX_QUANTA; x++){
		printf("%02d ", x);
		if(x % 31 == 0) printf("\n");
	}

	//print order of processes according to time
	printf("\n");

	for(int x = 0; x < CHAR_ARRAYMAX; x++){
		printf("%c  ", rr_process_order[x]);
		if(x % 31 == 0) printf("\n");
	}

	free(plist);
	free(rr_process_order);
	printf("\n");
	return;
}