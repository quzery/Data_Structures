#include<iostream>
#include<cstdio>
#include<cstdlib>
#include"_tree.h"

int main()
{
	SearchTree T = CreateTree();
	for (int i = 0; i < 5; i++)
		Insert(5*i, T);
	Tree f1 = Find(10, T);
	Tree f2 = FindMaxTree(f1);
	std::cout << f1->Right->Element << std::endl;
	Delete(15, T);
	std::cout << f1->Right->Element;
	//printf("%d,%d", f1->Element, f2->Element);
	return 0;
}