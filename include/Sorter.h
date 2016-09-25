#ifndef Sorter
#define Sorter

#include "process_producer.h"

/* Function: SortBy
*  sorts according to parameter, modifies the array directly
* parameters are the list of processes, according to Num_PROCESS. The input num decides what field to sort by 0 - arrival time; 1 - service time; 2 - priority
*/
void SortBy(struct process** plist, int num);

/* Function SortBy
*  species a range of the array to consider. useful for recursive calls when using the quicksort algorithm
*/
void SortByRec(struct process** plist, int num, int range_lo, int range_hi);

//DELETE THIS
void PrintServiceTimes(struct process** plist);

/* Function: swap
*  swaps the 2 objects through the use of memcpy. size is important as it determines the amount of bytes to copy from 1 location.
*  if the sizes are not equivilant no swap is done.
*/
void swap(void* objA, void* objB, size_t size_objA, size_t size_objB);

#endif