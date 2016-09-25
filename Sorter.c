#include <stdio.h>
#include <stdlib.h>

#include "Sorter.h"

#define TRUE 1
#define FALSE 0

void SortBy(struct process** plist, int num){
	int pivot_location = NUM_PROCESS - 2;
	int head = 0, temp;
	int inc_dec = 1;
	float service_time = (*plist)[pivot_location].service_time;
	while(TRUE){
		if((*plist)[head].service_time > service_time){
			swap(&(*plist)[head], &(*plist)[pivot_location], sizeof((*plist)[head]), sizeof((*plist)[pivot_location]));
			swap(&pivot_location, &head, sizeof(pivot_location), sizeof(head));
			inc_dec *= -1;
			head += inc_dec;
		}
		if(head == pivot_location) break;
		head += inc_dec;
	}
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