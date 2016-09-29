#include <stdio.h>
#include <stdlib.h>
#include "process_producer.h"
#include "Calculation.h"
#include "ShortestJobFirst.h"
#include <string.h>




void shortestJobFirst(struct process* o_plist) //process list is an array with all the processes 
//with info about arrival time and service time. 

{

	int currentQuanta; //keep track of the quanta during odering.
	

	struct process* newArrivalArray = malloc(sizeof(struct process) * NUM_PROCESS); //initialize arrays with size of NUM_PROCESS

	struct process* temp; //this is a single empty process called temp that I use for swapping.
    
    struct process* shortJobsExecuted = malloc(sizeof(struct process) * NUM_PROCESS); //create new array of shortsJobcompleted
   
   char CompletedProcesses [NUM_PROCESS]; //Just to put the completed processes in here for testing

	memcpy(newArrivalArray, o_plist, (sizeof(struct process) * NUM_PROCESS)); //copy processes into newArrivalArray
	
	SortBy(&newArrivalArray, 0); //Sort processes in array by arrival times only.

	newArrivalArray[0].actual_start_time = newArrivalArray[0].arrival_time; 
	
	//Since the first process will always be started.
	currentQuanta = newArrivalArray[0].arrival_time + newArrivalArray[0].service_time; 
	printf("Beginning quanta after first process: %d\n", currentQuanta);
printf("THIS IS SORTED BASED ON ARRIVAL TIME ONLY");
for(int i = 0; i < NUM_PROCESS; i++)
{
 printf("\n%s...................%d..............................%f\n", &newArrivalArray[i].name, newArrivalArray[i].arrival_time, newArrivalArray[i].service_time);
}//for testing purposes.
//HERE IS START OF SJF ordering. Return array of processes with correct order of SJF execution. 
//for(int i = 1; i< NUM_PROCESS; i++)
//{
	for(int j=1; j<NUM_PROCESS; j++) //we start at 1 because the first process (0 index) will start first always
	{ //each index is a Process.
		
		
			//swap around indexes within serviceArray
			if(newArrivalArray[j+1].arrival_time <= currentQuanta && newArrivalArray[j+1].arrival_time <= currentQuanta) //If Both processes arrived already.
			{
					if(newArrivalArray[j+1].service_time < newArrivalArray[j].service_time) //compare service times
					{
						temp = &newArrivalArray[j]; //added address symbol infront of array
						newArrivalArray[j] = newArrivalArray[j+1];
						newArrivalArray[j+1] = *temp; //dereferencing
						currentQuanta = currentQuanta + newArrivalArray[j].service_time;
						newArrivalArray[j].actual_start_time = currentQuanta; //this is the actual start time for each process
						printf("currentQuanta: %d ", currentQuanta);
					}
					else
					{
						newArrivalArray[j].actual_start_time = currentQuanta;
						currentQuanta = currentQuanta + newArrivalArray[j].service_time;
						printf("currentQuanta: %d ", currentQuanta);
					}
			}
			else if (newArrivalArray[j].arrival_time <= currentQuanta && newArrivalArray[j+1].arrival_time > currentQuanta)
			{
				//then we keep the process of j in that position since j+1 hasnt even arrived.
				newArrivalArray[j].actual_start_time = currentQuanta;
				currentQuanta = currentQuanta + newArrivalArray[j].service_time;
				printf("currentQuanta: %d ", currentQuanta);
			}

			else //This whole condition is for when neither processes have arrived at the current Quanta
			{
				while(currentQuanta-1 != newArrivalArray[j].arrival_time-1 || currentQuanta-1 < newArrivalArray[j].arrival_time-1) //So we 
				{
					newArrivalArray[j].actual_start_time = currentQuanta + 1;

					currentQuanta++;
					printf("currentQuanta: %d ", currentQuanta);
				}	
			}

		}
//	}
	//Displaying the order of each process with its name, arrival time, and service time.
	printf("\nThe Order of Processes for ShortestJobFirst\n");
	printf("\nProcess Name,   Arrival Time,    Actual Start Time,   Service Time\n");

for(int i = 0; i < NUM_PROCESS; i++)
{
 printf("\n%s...................%d..............................%d..............................%f\n", &newArrivalArray[i].name, newArrivalArray[i].arrival_time, newArrivalArray[i].actual_start_time, newArrivalArray[i].service_time);
}

		
		


//printshortestjobfirst(newArrivalArray);
return;
}
