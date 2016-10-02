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
	seller* h_sellers = malloc(sizeof(seller) * NUM_OF_H_SELLERS);//create h_sellers
	seller* m_sellers = malloc(sizeof(seller) * NUM_OF_M_SELLERS);//create m_sellers
	seller* l_sellers = malloc(sizeof(seller) * NUM_OF_L_SELLERS);//create l_sellers

	for(int x = 0; x < NUM_OF_H_SELLERS; x++){
		if(x < 10){
			h_sellers[x].name[0] = 'H'; 
			h_sellers[x].name[1] = 0;
			h_sellers[x].name[2] = x;
		}
		else{
			h_sellers[x].name[0] = 'H';
			h_sellers[x].name[1] = '1';
			h_sellers[x].name[2] = '2';
		}
		h_sellers[x].sales_price = 3;
	}

	//Populate all medium sellers
	for(int x = 0; x < NUM_OF_M_SELLERS; x++){
		if(x < 10){
			m_sellers[x].name[0] = 'M'; 
			m_sellers[x].name[1] = (char) 0;
			m_sellers[x].name[2] = (char) x;
		}
		else{
			m_sellers[x].name[0] = 'M';
			m_sellers[x].name[1] = '1';
			m_sellers[x].name[2] = '2';
		}
		m_sellers[x].sales_price = 2;
	}

	for(int x = 0; x < NUM_OF_L_SELLERS; x++){
		if(x < 10){
			l_sellers[x].name[0] = 'L'; 
			l_sellers[x].name[1] = (char) 48;
			l_sellers[x].name[2] = (char) (x + 48);
		}
		else{
			l_sellers[x].name[0] = 'L';
			l_sellers[x].name[1] = '1';
			l_sellers[x].name[2] = '2';
		}
		l_sellers[x].sales_price = 1;
	}

	l_sellers[5].sales_price = 10;

	print_sellers(l_sellers, NUM_OF_L_SELLERS);

	return 0;
}