#include <stdio.h>
#include <stdlib.h>

#include "Sorter.h"

#define TRUE 1
#define FALSE 0

void SortBy(struct process** plist, int num){
	int pivot_location = (int) (NUM_PROCESS / 2);
	int hi = NUM_PROCESS - 1;
	int lo = 0;
	float service_time = (*plist)[pivot_location].service_time;
	return;
}

void swap(void* objA, void* objB, size_t size_objA, size_t size_objB){

	if(size_objA == size_objB){
		void* tmp = malloc(size_objB);

		memcpy(tmp, objA, size_objA);
		memmove(objA, objB, size_objA);
		memmove(objB, tmp, size_objA);

		//struct process* test = objB;
		//printf("%c %f %d size: %d", (*test).name, (*test).service_time, (*test).priority, size_objB);
		//printf("\nEntered\n");
		free(tmp);
	}
	return;
}