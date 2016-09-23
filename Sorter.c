#include <stdio.h>
#include <stdlib.h>

#include "Sorter.h"

void SortBy(struct process** plist, int num){
	if(num == 0) swap(&(*plist[0]), &(*plist)[1], sizeof(*plist[0]), sizeof(*plist[1]));
	return;
}

void swap(void* objA, void* objB, size_t size_objA, size_t size_objB){

	if(size_objA == size_objB){
		void* tmp = malloc(size_objB);

		memcpy(tmp, objA, size_objA);
		memmove(objA, objB, size_objA);
		memmove(objB, tmp, size_objA);

		struct process* test = objB;
		//printf("%c %f %d size: %d", (*test).name, (*test).service_time, (*test).priority, size_objB);
		//printf("\nEntered\n");
		free(tmp);
	}
	return;
}