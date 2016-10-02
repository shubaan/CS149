#include <stdio.h>
#include <stdlib.h>
#include "seller.h"

void print_sellers(seller* list, int length){
	char* p; 
	void* i_p = &list[0].sales_price;
	for(int x = 0; x < length; x++){
		p = (char*) &list[x];
		printf("%c-%c%c Sales Price: %d\n", *p, *(p + 1), *(p + 2), *( (int*) i_p) );
		( (seller*) i_p )++;

	}
	return;

}