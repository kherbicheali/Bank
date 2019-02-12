

float sold=90;
void *credit (void *crdt){
	sold = sold + *(float *) crdt;		
}

void *debit (void *crdt){
	sold = sold - *(float *) crdt;
}

float getSold (void){
	return(sold);
}

