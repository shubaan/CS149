#include <stdio.h>
#include <stdlib.h>
#include "string.h"

static void swap(void* obj_a, void* obj_b, int size_a, int size_b){
	if(size_a != size_b) return;
	void* tmp = malloc(size_a);
	memcpy(tmp, obj_a, size_a);
	memmove(obj_a, obj_b, size_a);
	memmove(obj_b, tmp, size_a);
	free(tmp);
}

void sort(void* start_obj, int* int_comp, int obj_size, int length){
	//Set pointer to beginning of array
	length -= 1;
	char* lo; char* hi;
	char* beg_objb = (char*) start_obj;
	char* int_compb = (char*) int_comp;
	pivot = (char*) start_obj;
	pivot += (obj_size * length); 

	//printf("Comp1: %d Comp2: %d\n", *( (int*) (int_compb) ), *( (int*) (int_compb + (obj_size * length) ) ) );
	//printf("%d", *((int*)(beg_objb + (obj_size * length))))
	for(int x = 0; x =< length; x++){
		if( *( (int*) (int_compb) ) < *( (int*) (int_compb + (obj_size * x) ) ) ){
			swap(beg_objb, (beg_objb + (obj_size * x)), obj_size, obj_size);
		}
	}
	return;
}