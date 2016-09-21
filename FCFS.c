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
			*runtime = (*runtime * -1) + (float) MAX_QUANTA;
			break;
		} 
		else if(counter > NUM_PROCESS){
		*runtime = (float) MAX_QUANTA - *runtime;
			break;
		}
		printf("%f\n", *runtime);
		
		*runtime = *runtime - plist[counter].service_time;
		counter++;
	}
	return;
}