#ifndef CUSTOMER
#define CUSTOMER

#define NUM_OF_CUSTOMERS 10

struct customer{
	//char* name;
	int arrival_time;
};

typedef struct customer customer;

void make_customers(customer** queue, int length);

void print_customers(customer* list, int length);

#endif