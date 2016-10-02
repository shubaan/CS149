#ifndef SELLER
#define SELLER

#include "customer.h"

struct seller{
	char name[3];
	int sales_price; //1 = L; 2 = M; 3 = H
	customer* start_queue; // Start of customer queue
};

typedef struct seller seller;

/**
 * [print_sellers prints a list of - their name and their sales price]
 * @param list   [list of sellers]
 * @param length [the number of sellers]
 */
void print_sellers(seller* list, int length);

void* sell_seats(void* seat_seller);

#endif