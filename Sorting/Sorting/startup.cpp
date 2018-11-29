#include<stdio.h>
#include"Sort.h"


int main()
{
	ElementType a[100];
	for (int i = 0; i < 100; i++)
		a[i] = 100 - i;
	printarray(a, 100);
	//Insert_sorting(a, 10);
	//Bubble_sorting(a, 10);
	Quick_sorting(a, 100);
	//Swap(&a[0], &a[1]);
	printarray(a, 100);
}
