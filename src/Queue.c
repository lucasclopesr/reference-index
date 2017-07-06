#include "../lib/qItem.h"
#include "../lib/qCell.h"
#include "../lib/Queue.h"
#include <stdlib.h>

void createEmptyQueue(Queue *q){
	q->first       = (qPointer) malloc(sizeof(qCell));
	q->last        = q->first;
	q->first->next = NULL;
}

int isQueueEmpty(const Queue *q){
	return (q->first == q->last);
}

void insertInQueue(int item, Queue *q){
	q->last->next        = (qPointer) malloc(sizeof(qCell));
	q->last              = q->last->next;
	q->last->content.key = item;
	q->last->next        = NULL;
}

int deleteFromQueue(Queue *q, qItem *item){
	qPointer p;

	if(isQueueEmpty(q)){
		return 0;
	}

	p = q->first;
	q->first = q->first->next;
	free(p);
	*item = q->first->content;
	return 1;
}