#include "bank.h"

float sold=90; // l'ancien montant présent sur le compte 
int compt1=0; // compteur sur le nombre d'utilisation du thread credit
int compt2=0; // compteur sur le nombre d'utilisation du thread debit

void *credit (void *crdt){
	
	while(compt1>=0 && compt1<100) {
		sold = sold + *(float *) crdt;
		compt1++;
		printf("sold_after_credit[%d] =%f  \t credit_thread_ID =%ld \n",compt1,sold,pthread_self()); 
		// afficher la valeur du solde après opération crédit, la valeur du compteur actuel et l'identifiant du thread credit 
		usleep(100000);
		// sleep( unsigned int second), we'll use usleep ( unsigned int microsecond) 
	}
	return NULL;		
}

void *debit (void *crdt){
	
	while(compt2>=0 && compt2<100) {
		sold = sold - *(float *) crdt;
		compt2++;
		printf("sold_after_debit[%d] =%f  \t debit_thread_ID =%ld \n",compt2,sold,pthread_self());
		// afficher la valeur du solde après opération débit, la valeur du compteur actuel et l'identifiant du thread debit
		usleep(100000);
	}
	return NULL;
}

float getSold (void){
	return(sold);
}


/*
Bonjour M;
Je suis un étudiant en M1 EEA ISTR, j'ai voulu faire un petit exemple sur les threads. Alors c'est l'exemple d'un automate d'une banque sur lequel un opérateur peut faire deux opérations "méthodes" CREDIT respectivement DEBIT qui crédite respectivement débite de l'argent dans/du le compte bancaire, j'ai mis en place deux threads un pour chaque opération.
Mon but c'est de ne pas faire une exclusion mutuelle si les deux opérations arrivent au même temps dans le but de trouver l'existance d'un problème c'est à dire prouver l'existance d'une ressource partagée (à priori c'est le solde actuel) en faisant executer le programme C une infinité de fois. Mais je rencotre quelques problèmes après execution:
- Le programme arrete de s'executer meme en utilisant une boucle infinie. 
- L'identifiant des threads changent à chaque exécution, est-ce normal ?
Alors est-ce la bonne démarche à suivre pour trouver le problème ? sinon comment prouver l'existance d'une ressource partagée ?
PS: le code C est disponible en pièce jointe.
Bien cordialemet;
Kherbiche Ali  
*/   
