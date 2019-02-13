#include "bank.h"
 
int main (void){
	float sld = 100;
	pthread_t th1,th2,th3;
	int i = 0;

	printf("main_thread_ID =%d  \n ",getpid()); // afficher l'identifiant du thread main 	
	for (i;i<100;i++) {
	pthread_create(&th1, NULL, credit, &sld);	
	pthread_create(&th2, NULL, debit, &sld);
	//pthread_create(&th2, NULL, debit, &sld);

	pthread_join(th1, NULL);
	pthread_join(th2, NULL);
	}
	printf("fin \n");
	return 0;
	
}

