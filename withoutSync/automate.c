#include "bank.h"
 
void main (void){
	
	float sld = 100;
	pthread_t *th1,*th2;	
	while(1){
	pthread_create(th1, NULL, credit, &sld);
	pthread_create(th2, NULL, debit, &sld);
	pthread_join(th1, NULL);
	pthread_join(th2, NULL);
	//printf("sold =%f\n",getSold());
	}
}

