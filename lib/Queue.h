#ifndef QUEUE_H
#define QUEUE_H

typedef struct{
	qPointer first, last; //Ponteiros para nós das filas
} Queue;

void createEmptyQueue(Queue*);
int isQueueEmpty(const Queue*);
void insertInQueue(int, Queue*);
int deleteFromQueue(Queue*, qItem*);

#endif