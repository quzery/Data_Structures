#include<cstdio>
#include<cstdlib>
#include"_AvlTree.h"

static int Max(int a, int b)
{
	if (a < b) return b;
	else return a;
}


static int getHeight(AvlTree T)
{
	if (T == NULL)
		return -1;
	else
		return T->Height;
}

AvlTree CreateAvlTree()
{
	AvlTree T = AvlTree(malloc(sizeof(struct AvlTreeNode)));
	T->Element = 0;
	T->Height = 0;
	T->Left = NULL;
	T->Right = NULL;
	return T;
}

Position Find(ElementType X, AvlTree T)
{
	if (T == NULL) return NULL;
	else if (X < T->Element)  Find(X, T->Left);
	else if (X > T->Element)  Find(X, T->Right);
	return T;
}


static AvlTree SingleRotateWithLeft(Position K2)
{
	Position K1;

	K1 = K2->Left;
	K2->Left = K1->Right;
	K1->Right = K2;
	K2->Height = Max(getHeight(K2->Left), getHeight(K2->Right)) + 1;
	K1->Height = Max(getHeight(K1->Left), getHeight(K1->Right)) + 1;
	return K1;
}

static AvlTree SingleRotateWithRight(AvlTree K2)
{
	AvlTree K1 = K2->Right;
	K2->Right = K1->Left;
	K1->Left = K2;
	K2->Height = Max(getHeight(K2->Left), getHeight(K2->Right)) + 1;
	K1->Height = Max(getHeight(K1->Left), getHeight(K1->Right)) + 1;
	return K1;
}


static AvlTree DoubleRotateWithLeft(AvlTree K3)
{
	K3->Left = SingleRotateWithRight(K3->Left);
	return SingleRotateWithLeft(K3);
}

static AvlTree DoubleRotateWithRight(AvlTree K3)
{
	K3->Right = SingleRotateWithLeft(K3->Right);
	return SingleRotateWithRight(K3);
}


AvlTree Insert(ElementType X, AvlTree &T)
{
	if (T == NULL)
	{
		T = CreateAvlTree();
		T->Element = X;
	}
	else if (X < T->Element)
	{
		T->Left = Insert(X, T->Left);
		if (getHeight(T->Left) - getHeight(T->Right) == 2)
		{
			if (X < T->Left->Element) T = SingleRotateWithLeft(T);
			else T = DoubleRotateWithLeft(T);
		}
	}

	else if (X > T->Element)
	{
		T->Right = Insert(X, T->Right);
		if (getHeight(T->Right) - getHeight(T->Left) == 2)
		{
			if (X > T->Right->Element)   T = SingleRotateWithRight(T);
			else  T = DoubleRotateWithRight(T);
		}
	}
	T->Height = Max(getHeight(T->Left), getHeight(T->Right)) + 1;
	return T;
}

void PrintAvlTree(AvlTree T)
{
	if (T != NULL)
	{
		PrintAvlTree(T->Left);
		printf("%d\n", T->Element);
		PrintAvlTree(T->Right);
	}
}