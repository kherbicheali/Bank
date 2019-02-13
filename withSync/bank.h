#if !defined(bank_h_)
#define bank_h_

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *credit (void *crdt);
void *debit (void *crdt);
float getSold (void);
#endif
