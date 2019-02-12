#include "bank.h"
 
void main (void){
	float sld = 100;
	pthread_t *th1,*th2;
	pthread_create(th1, NULL, credit, &sld);
	pthread_create(th2, NULL, debit, &sld);
	printf("sold =%f\n",getSold());
}
