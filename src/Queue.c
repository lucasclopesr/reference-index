#include "../lib/qItem.h"
#include "../lib/qCell.h"
#include "../lib/Queue.h"
#include <stdlib.h>
#include <stdio.h>

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

void printQueue(Queue q, FILE *outputFile){
	qPointer p = q.first;
	if(!isQueueEmpty(&q)){
		// printf("Lines: ");
		while(p != NULL){
			p = p->next;
			if(p == NULL) break;
			fprintf(outputFile, "%d ", p->content.key);
		}
	}
}