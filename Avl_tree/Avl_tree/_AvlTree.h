#ifndef _AvlTree_H

typedef int ElementType;
typedef struct AvlTreeNode *PtrToAvl;
typedef PtrToAvl AvlTree;
typedef PtrToAvl Position;

AvlTree CreateAvlTree();
Position Find(ElementType X, AvlTree T);
AvlTree Insert(ElementType X, AvlTree &T);
//AvlTree Delete(ElementType X, AvlTree T);
void PrintAvlTree(AvlTree T);
//int getHeight(AvlTree T);
#endif // !_AvlTree_H

struct AvlTreeNode
{
	ElementType Element;
	Position Left;
	Position Right;
	int Height;
};


