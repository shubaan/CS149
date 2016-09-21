#ifndef PROCESS_PRODUCER
#define PROCESS_PRODUCER

#define NUM_PROCESS 15
#define MAX_QUANTA 100

struct process{
	int arrival_time;
	float service_time;
	int priority;
	char name;
};

void PrintProcessList(struct process* a);

void CreateProcesses(struct process** process_list);

#endif