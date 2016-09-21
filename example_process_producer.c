#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define NUM_PROCESS 5 // USED TO DETERMINE NUMBER OF PROCESSES WANTED

struct process{
	int arrival_time;
	int service_time;
	int priority;
	char name;
};

int main(){
	int seed = time(NULL);
	srand(seed);
	char alphabet[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	// setting local variables
	int arrival_time;
	int service_time;
	int priority;
	struct process* process_list = malloc(sizeof(struct process) * NUM_PROCESS);
	// generate proesses
	for(int x = 0; x < NUM_PROCESS; x++){
		arrival_time = rand() % 100;
		service_time = rand() % 11;
		priority = rand() % 5;
		if( service_time == 0 ) service_time += 1;
		if( priority == 0 ) priority += 1;

		process_list[x].arrival_time = arrival_time;
		process_list[x].service_time = service_time;
		process_list[x].priority = priority;
		process_list[x].name = alphabet[x];
	}

	// Print Processes for testing
	for(int x = 0; x < NUM_PROCESS; x++){
		printf("%c: Service Time: %d Priority: %d Arrival Time: %d\n", process_list[x].name, process_list[x].service_time, process_list[x].priority, process_list[x].arrival_time);
	}

	return 0;
}


