#ifndef FCFS
#define FCFS

/* Function: FirstCome
*  takes in pointer to a process list with a number of elements defined by NUM_RPOCESS. runetime is a pointer to a float which will store the total runtime.
*  TODO//currently doesn't work because it doesn't take into account arrival time
*/
void FirstCome(struct process* plist, float* runtime);

#endif