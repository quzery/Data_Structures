#include<cstdio>
#include<cstdlib>
#include"_queue.h"

Queue CreateQueue()
{
	Queue Q = Queue(malloc(sizeof(struct Queue_str)));
	//Position P = Position(malloc(sizeof(struct Node)));
	//P->Element = 0;
	//P->Next = NULL;
	Q->Rear = NULL;
	Q->Front = NULL;
	Q->Size = 0;
	return Q;
}

Queue Add(ElementType X, Queue Q)
{
	Position P = Position(malloc(sizeof(struct Node)));
	P->Element = X;
	P->Next = NULL;
	if (Q->Size == 0)
	{
		Q->Front = P;
		Q->Rear = P;
	}
	else
	{
		Q->Rear->Next = P;
		Q->Rear = P;
		if(Q->Size == 1) Q->Front->Next = Q->Rear;
	}
	
	Q->Size++;
	return Q;
}

Queue Delete(Queue Q)
{
	Position P;
	if (Q->Size > 1)
	{
		P = Q->Front;
		Q->Front = Q->Front->Next;
		free(P);
	}
	else  
	{
		free(Q->Front);
		Q->Front = NULL;
		Q->Rear = NULL;
	}
	Q->Size--;
	return Q;
}