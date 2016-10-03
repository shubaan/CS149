#ifndef SHARED
#define SHARED
#include "pthread.h"
#include <stdbool.h>

#define TOTAL_SEATS 100

pthread_mutex_t seat_access;
pthread_cond_t cond;
int filled_seats;

#endif