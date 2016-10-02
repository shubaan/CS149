#ifndef SELLER
#define SELLER

#include "customer.h"

struct seller{
	char name[3];
	int sales_price; //1 = L; 2 = M; 3 = H
	customer* start_queue; // Start of customer queue
};

typedef struct seller seller;

void print_sellers(seller* list, int length);

#endif