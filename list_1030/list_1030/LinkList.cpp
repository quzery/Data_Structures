
#include <iostream>
#include"_List.h"

int main()
{
	List L = CreateList();
	Position p,f;
	add(4, L);
	p = LastPosition(L);
	f = Find(5, L);
	printf("this is %d and %d", p->Element,f);

}

