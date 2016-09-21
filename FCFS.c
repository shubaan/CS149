#include <stdio.h>
#include <stdlib.h>
#include "process_producer.h"
#include "FCFS.h"

#define TRUE 1
#define FALSE 0

float FCFS(struct process* plist){
	float time = (float) MAX_QUANTA;
	int counter = 0;
	while(TRUE){
		if(time <= 0){
			time = (time * -1) + (float) MAX_QUANTA;
			break;
		} 
		else if(counter > NUM_PROCESS){
		time = (float) MAX_QUANTA - time;
			break;
		}
		printf("%f\n", time);
		
		time = time - plist[counter].service_time;
		counter++;
	}
	return time;
}