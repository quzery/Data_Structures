#ifndef _queue_H

typedef int ElementType;
typedef struct Node *PtrToNode;
typedef struct Queue_str *PtrToQueue_str;
typedef PtrToNode Position;
typedef PtrToQueue_str Queue;

Queue CreateQueue();
Queue Add(ElementType X, Queue Q);
Queue Delete(Queue Q);


#endif // !_queue_H

struct Node
{
	ElementType Element;
	Position Next;
};

struct Queue_str
{
	Position Front;
	Position Rear;
	int Size;
};