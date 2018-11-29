#include<cstdio>
#include<cstdlib>
#include<iostream>
#include"_AvlTree.h"

int main()
{
	AvlTree T = CreateAvlTree();
	for (int i = 0; i < 10; i++)
		Insert(i, T);
	PrintAvlTree(T);
	int a = T->Height;
	printf("height = %d ", a);
}