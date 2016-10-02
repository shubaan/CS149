#include <stdio.h>
#include <stdlib.h>
#include "shared.h"
#include "seller.h"


void print_sellers(seller* list, int length){
	char* p; 
	char* i_p =(char*) &list[0].sales_price;
	for(int x = 0; x < length; x++){
		p = (char*) &list[x];
		printf("%c-%c%c Sales Price: %d\n", *p, *(p + 1), *(p + 2), *( (int*) i_p) );
		i_p += (sizeof(seller));
	}
	return;
}

void* sell_seats(void* seat_seller){
	while(!filled_seats){
	pthread_mutex_lock(&seat_access);
	for(int x = 0; x < 5; x++){
		printf("%d\n", 5);
	}
	filled_seats++;
	pthread_mutex_unlock(&seat_access);
	}
	pthread_exit(NULL);
}
