// CX1007 Data Structures

#include <stdio.h>

#include "Queue.h"

////////////////////////////////////////////////////////////////////////////////

void enqueue(Queue *q, int item){
	insertNode(&(q->ll), q->ll.size, item);
}

int dequeue(Queue *q){
	int item;
	item = ((q->ll).head)->item;
	removeNode(&(q->ll), 0);
	return item;
}

int isEmptyQueue(Queue *q){
	if ((q->ll).size == 0) return 1;
	return 0;
}

////////////////////////////////////////////////////////////////////////////////
//@Cheejyg
////////////////////////////////////////////////////////////////////////////////

int peak(Queue *q) {
	int item;
	item = ((q->ll).head)->item != NULL ? ((q->ll).head)->item : NULL;
	return item;
}