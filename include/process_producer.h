#ifndef PROCESS_PRODUCER
#define PROCESS_PRODUCER

#define NUM_PROCESS 36 //26 max possible number
#define MAX_QUANTA 100
#define CHAR_ARRAYMAX 150

/* Struct: process
*  struct created in accordance to Ezzat's specifications
*/
struct process{
	int arrival_time; // time process arrives in queue
	float service_time; // how much time to finish process
	int priority; // priority 1 - 4, 1 highest priority for priority based scheduling
	char name; // name A-Z or 0 - 9
	int actual_start_time; // when the process is contacted by CPU for first time
	int end_time; // process finishes
};

/* Function: PrintProcessList
*--------------------------------
* Pass in an array of struct process and it will print all attributes and processes
*/
void PrintProcessList(struct process* a);

/* Function: CreateProcess
* pass in a pointer, this function constructs an array of struct process. How many
* process is determined by the macro NUM_PROCESS and the max arrival time is determined by MAX_QUANTA
*/
void CreateProcesses(struct process** process_list);
//void SortProcesses(struct process** process_list);

#endif