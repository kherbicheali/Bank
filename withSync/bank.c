#include "bank.h"

float sold=90; // l'ancien montant présent sur le compte 
int compt1=0; // compteur sur le nombre d'utilisation du thread credit
int compt2=0; // compteur sur le nombre d'utilisation du thread debit
pthread_mutex_t lock;

void *credit (void *crdt){ 
	//while(compt1>=0 && compt1<100) {
		pthread_mutex_lock(&lock);
		sold = sold + *(float *) crdt;
		//compt1++;		
		compt1=(compt1+1)%101;
		printf("sold_after_credit[%d] =%f  \t credit_thread_ID =%ld \n",compt1,sold,pthread_self()); 
		// afficher la valeur du solde après opération crédit, la valeur du compteur actuel et l'identifiant du thread credit 
		usleep(100000);
		// sleep( unsigned int second), we'll use usleep ( unsigned int microsecond) 
		pthread_mutex_unlock(&lock);
	//}
	return NULL;		
}

void *debit (void *crdt){
	
	//while(compt2>=0 && compt2<100) {
		pthread_mutex_lock(&lock);
		sold = sold - *(float *) crdt;
		//compt2++;
		compt2=(compt2+1)%101;
		printf("sold_after_debit[%d] =%f  \t debit_thread_ID =%ld \n",compt2,sold,pthread_self());
		// afficher la valeur du solde après opération débit, la valeur du compteur actuel et l'identifiant du thread debit
		usleep(100000);
		pthread_mutex_unlock(&lock);
	//}
	return NULL;
	//compt2=0
}
float getSold (void){
	return(sold);
}
