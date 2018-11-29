#include<cstdio>
#include<cstdlib>
#include"_tree.h"

SearchTree CreateTree()
{
	SearchTree T = Tree(malloc(sizeof(struct TreeNode)));
	T->Element = 0;
	T->Left = NULL;
	T->Right = NULL;
	return T;
}

Tree Find(ElementType X, SearchTree T)
{
	if (T == NULL )  return NULL;
	if (T->Element > X)  return Find(X, T->Left);
	else if (T->Element < X)  return Find(X, T->Right);
	else return T;
}

Tree FindMaxTree(SearchTree T)
{
	while (T != NULL && T->Right != NULL) 
	{
		T = T->Right;
	}
	return T;
}

Tree FindMinTree(SearchTree T)
{
	while (T != NULL && T->Left != NULL)
	{
		T = T->Left;
	}
	return T;
}

SearchTree Insert(ElementType X, SearchTree T)
{
	if (T == NULL)
	{
		T = Tree(malloc(sizeof(struct TreeNode)));
		T->Element = X;
		T->Left = T->Right = NULL;
	}
	else if (T->Element > X)  T->Left = Insert(X, T->Left);
	else if (T->Element < X)  T->Right = Insert(X, T->Right);
	return T;
}

SearchTree Delete(ElementType X, SearchTree T)
{
	Tree tem;
	if (T == NULL) return T;
	else if(T->Element > X)  T->Left = Delete(X, T->Left);
	else if (T->Element < X)  T->Right = Delete(X, T->Right);
	else if (T->Left && T->Right)
	{
		tem = FindMinTree(T->Right);
		T->Element = tem->Element;
		T->Right = Delete(T->Element, T->Right);
	}
	else
	{
		tem = T;
		if (T->Left == NULL)  T = T->Right;
		else if (T->Right == NULL)  T = T->Left;
		free(tem);
	}
	return T;
}