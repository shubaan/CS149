#include <stdio.h>
#include <stdlib.h>
#include "pthread.h"

pthread_mutex_t print_lock;

/**
 * [print adds and prints from 1 - 1000]
 * @param  incr [when making threads, the parameters can only be type void*. It must be typed after it comes in]
 * @return      [return value must always be a void*, NULL works if nothing is being returned]
 */
void *print(void* incr){
	pthread_mutex_lock(&print_lock);
	int* value = (int*) incr;
	for(int x = 0; x < 1000; x++){
	 *value += x;
	 printf("%d\n", x);
	}
	pthread_mutex_unlock(&print_lock);
	return NULL;
}
/**
 * [main show a test demonstration of creating threads]
 * @return [0 on completion]
 */
int main(){
	pthread_t print_thread;
	pthread_t print_thread2;
	int incr;
	incr = 0;

	pthread_mutex_init(&print_lock, NULL);

	pthread_create(&print_thread, NULL, print, &incr);
	pthread_create(&print_thread2, NULL, print, &incr);

	pthread_join(print_thread2, NULL);
	pthread_join(print_thread, NULL);

	pthread_mutex_destroy(&print_lock);

	printf("thread %d", incr);
	return 0;
}