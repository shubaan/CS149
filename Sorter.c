#include <stdio.h>
#include <stdlib.h>

#include "Sorter.h"

#define TRUE 1
#define FALSE 0

void SortBy(struct process** plist, int num){
	int pivot_location = NUM_PROCESS - 1;
	int head = 0;
	int inc_dec = 1;
	float compare_num = (*plist)[pivot_location].service_time;

	while(TRUE){
		if((*plist)[head].service_time > compare_num && head < pivot_location){
			swap(&(*plist)[head], &(*plist)[pivot_location], sizeof((*plist)[head]), sizeof((*plist)[pivot_location]));
			swap(&pivot_location, &head, sizeof(pivot_location), sizeof(head));
			inc_dec *= -1;
			head += inc_dec;
		}
		else if((*plist)[head].service_time < compare_num && head > pivot_location){
			swap(&(*plist)[head], &(*plist)[pivot_location], sizeof((*plist)[head]), sizeof((*plist)[pivot_location]));
			swap(&pivot_location, &head, sizeof(pivot_location), sizeof(head));
			inc_dec *= -1;
			head += inc_dec;
		}
		else head += inc_dec;
		if(head == pivot_location) break;

	}
	//PIVOT LOCATION - 1 WHAT IF 0?

	//TEST ORDER

	if(pivot_location > 0) SortByRec(&*plist, num, 0, pivot_location);
	if(pivot_location < NUM_PROCESS - 1) SortByRec(&*plist, num, pivot_location + 1, NUM_PROCESS - 1);
	PrintServiceTime(&*plist);
	return;
}

void SortByRec(struct process** plist, int num, int range_lo, int range_hi){
	if(range_hi - range_lo <= 1) return;
	int pivot_location = range_hi;
	int head = range_lo;
	int inc_dec = 1;
	float compare_num = (*plist)[pivot_location].service_time;
	while(TRUE){
		if((*plist)[head].service_time > compare_num && head < pivot_location){
			swap(&(*plist)[head], &(*plist)[pivot_location], sizeof((*plist)[head]), sizeof((*plist)[pivot_location]));
			swap(&pivot_location, &head, sizeof(pivot_location), sizeof(head));
			inc_dec *= -1;
			head += inc_dec;
		}
		else if((*plist)[head].service_time < compare_num && head > pivot_location){
			swap(&(*plist)[head], &(*plist)[pivot_location], sizeof((*plist)[head]), sizeof((*plist)[pivot_location]));
			swap(&pivot_location, &head, sizeof(pivot_location), sizeof(head));
			inc_dec *= -1;
			head += inc_dec;
		}
		else head += inc_dec;
		if(head == pivot_location) break;
	}	
	if(pivot_location > 0) SortByRec(&*plist, num, range_lo, pivot_location - 1);
	if(pivot_location < NUM_PROCESS - 1) SortByRec(&*plist, num, pivot_location, range_hi);
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