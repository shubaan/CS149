#ifndef Sorter
#define Sorter

#include "process_producer.h"

/* Function: SortBy
*  sorts according to parameter, modifies the array directly
* parameters are the list of processes, according to Num_PROCESS. The input num decides what field to sort by 0 - arrival time 1 - service time 2 - priority
*/
void SortBy(struct process** plist, int num);

#endif