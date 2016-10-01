#include <stdio.h>
#include <stdlib.h>
#include "pthread.h"
#include "sched.h"
#include "semaphore.h"
#include "seller.h"
#include "customer.h"

#define NUM_OF_H_SELLERS 1
#define NUM_OF_M_SELLERS 10
#define NUM_OF_L_SELLERS 10

int main(){
	seller* h_seller = malloc(sizeof(seller) * NUM_OF_H_SELLERS);//create h_sellers
	seller* m_sellers = malloc(sizeof(seller) * NUM_OF_M_SELLERS);//create m_sellers
	seller* l_sellers = malloc(sizeof(seller) * NUM_OF_L_SELLERS);//create l_sellers

	for(int x = 0; x < NUM_OF_H_SELLERS; x++){

		h_sellers[x].name = malloc(sizeof(char) * 3);
		if(x < 10){
			h_sellers[x].name[0] = 'H'; 
			h_sellers[x].name[1] = (char) 0;
			h_sellers[x].name[2] = (char) x;
		}
	}

	return 0;
}