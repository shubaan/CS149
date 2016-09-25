#include <stdio.h>
#include <stdlib.h>

#include "Sorter.h"

#define TRUE 1
#define FALSE 0

void SortBy(struct process** plist, int num){
	int pivot_location = NUM_PROCESS - 1;
	int head = 0;
	int inc_dec = 1;
	float service_time = (*plist)[pivot_location].service_time;

	while(TRUE){
		if((*plist)[head].service_time > service_time && head < pivot_location){
			swap(&(*plist)[head], &(*plist)[pivot_location], sizeof((*plist)[head]), sizeof((*plist)[pivot_location]));
			swap(&pivot_location, &head, sizeof(pivot_location), sizeof(head));
			inc_dec *= -1;
			head += inc_dec;
			printf("Current Head: %d Current Pivot Location: %d\n", head, pivot_location);
		}
		else if((*plist)[head].service_time < service_time && head > pivot_location){
			swap(&(*plist)[head], &(*plist)[pivot_location], sizeof((*plist)[head]), sizeof((*plist)[pivot_location]));
			swap(&pivot_location, &head, sizeof(pivot_location), sizeof(head));
			inc_dec *= -1;
			head += inc_dec;
			printf("Current Head: %d Current Pivot Location: %d\n", head, pivot_location);

		}
		else head += inc_dec;
		PrintServiceTime(&*plist);
		if(head == pivot_location) break;

	}
	//PIVOT LOCATION - 1 WHAT IF 0?

	//REMOVE THIS
	PrintServiceTime(&*plist);
	//SortByRec(&*plist, num, 0, pivot_location);
	//SortByRec(&*plist, num, pivot_location, NUM_PROCESS - 1);
	return;
}

void SortByRec(struct process** plist, int num, int range_lo, int range_hi){
	if(range_hi - range_lo <= 1) return;
	while(TRUE){
		break;
	}	
	return;
}

void PrintServiceTime(struct process** plist){
	for(int x = 0; x < NUM_PROCESS; x++){
		printf("%.2f, ", (*plist)[x].service_time);
	}
	printf("\n");
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