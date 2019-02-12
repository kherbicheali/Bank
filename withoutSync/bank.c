

float sold=90;
int compt1=0;
int compt2=0;
void *credit (void *crdt){
	sold = sold + *(float *) crdt;
	compt1++;
	printf("credit =%f \t %d\n ",sold,compt1);
	sleep(100);		
}

void *debit (void *crdt){
	sold = sold - *(float *) crdt;
	compt2++;
	printf("debit =%f \t %d\n",sold,compt2);
	sleep(100);
}

float getSold (void){
	return(sold);
}

