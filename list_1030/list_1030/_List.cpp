#include<cstdio>
#include<cstdlib>
#include"_List.h"


List CreateList()
{
	Position P = Position(malloc(sizeof(struct Node)));
	if (P == NULL)  printf("out of space!");
	P->Next = NULL;
	return P;
}

List MakeEmpty(List L) 
{
	if (L->Next != NULL)
		L->Next = NULL;
	return L;

}

int IsEmpty(List L)
{
	return L->Next == NULL;
}

int IsLast(Position P, List L)
{
	return P->Next == NULL;
}

Position Find(ElementType X, List L)
{
	Position P = L->Next;
	//while (P->Element != X && P != NULL)
	while(P != NULL && P->Element != X)
		P = P->Next;
	return P;
	/*if (P != NULL) return P;
	else
	{
		printf("error! X is not exsit in L!");
		return NULL;
	}*/
}

Position FindPrevious(ElementType X, List L)
{
	Position P = L->Next;
	//while (P->Next->Element == X && P->Next !=NULL)
	while (P->Next != NULL && P->Next->Element != X)
		P = P->Next;
	return P;
	/*if (P != NULL) return P;
	else
	{
		printf("error! ");
		return NULL;
	}*/
}

void Delete(ElementType X, List L)
{
	Position P = Find(X, L);
	Position F = FindPrevious(X, L);
	F->Next = P->Next;
	free(P);
}

void Insert(ElementType X, List L, Position P)
{
	Position tem = Position(malloc(sizeof(struct Node)));
	if (tem == NULL)  printf("out of space!");
	tem->Element = X;
	tem->Next = P->Next;
	P->Next = tem;
}

Position LastPosition(List L)
{
	Position P = L;
	if (L->Next != NULL)
	{
		while (P->Next != NULL)
		{
			P = P->Next;
		}
	}
	//else P = L;
	return P;
}

void DeleteList(List L)
{
	Position P, F;
	P = L;
	while (P->Next != NULL)
	{
		F = P;
		P = P->Next;
		free(F);
	}
	free(P);
}

void add(ElementType X, List L)
{
	Position P = LastPosition(L);
	Insert(X, L, P);
}