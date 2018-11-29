#include<cstdio>
#include<cstdlib>
#include"_queue.h"

int main()
{
	Queue Q = CreateQueue();
	for(int i =0;i<10;i++)
		Add(i, Q);
	for (int i = 0; i < 9; i++)
		Delete(Q);
	printf("Front=%d, Rear=%d, Size=%d", Q->Front->Element, Q->Rear->Element,Q->Size);

}