#ifndef _List_H
#define _List_H

struct Node;
typedef struct Node *PtrToNode;
//typedef PtrToNode List;
typedef struct Node *List;
typedef PtrToNode Position;
typedef int ElementType;

List CreateList();
List MakeEmpty(List L);
Position LastPosition(List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(ElementType X, List L);
Position FindPrevious(ElementType X, List L);
void Delete(ElementType X, List L);
void Insert(ElementType X, List L, Position P);
void DeleteList(List L);
void add(ElementType X, List L);
//Position Header(List L);
//Position First(List L);
//Position Advance(Position P);
//ElementType Retrieve(Position P);




struct Node
{
	ElementType Element;
	Position Next;
};



#endif // !_List_H