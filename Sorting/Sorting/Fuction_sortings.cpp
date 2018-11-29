#include<stdio.h>
#define cutoff (3)
typedef int ElementType;


void printarray(ElementType a[], int size)
{
	for (int j = 0; j < size; j++)
		printf("%d,", a[j]);
	printf("\n");
}


void Insert_sorting(ElementType a[], int size)
{
	int i, j;
	for (i = 1; i < size; i++)
	{
		ElementType tem = a[i];
		for (j = i; j > 0 && a[j - 1] > tem; j--)
			a[j] = a[j - 1];
		a[j] = tem;

	}
}


void Bubble_sorting(ElementType a[], int size)
{
	for(int i = 0;i < size;i++)
		for(int j = 0;j < size - i -1;j++)
			if (a[j] > a[j + 1])
			{
				ElementType tem = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tem;
			}
}


//quick_sort

void Swap(ElementType *a, ElementType *b)
{
	ElementType tem = *a;
	*a = *b;
	*b = tem;
}

//三数中值分割
ElementType Median3(ElementType a[], int left, int right)
{
	int center = (left + right) / 2;
	if (a[left] > a[center]) Swap(&a[left], &a[center]);
	if (a[left] > a[right]) Swap(&a[left], &a[right]);
	if (a[center] > a[right]) Swap(&a[center], &a[right]);
	Swap(&a[center], &a[right - 1]);
	return a[right - 1];
}

void Qsort(ElementType a[], int left, int right)
{
	if (left + cutoff < right)
	{
		ElementType pivot = Median3(a, left, right);
		int i = left, j = right - 1;
		for (; ; )
		{
			while (a[++i] < pivot) {}
			while (a[--j] > pivot) {}
			if (i < j)
				Swap(&a[i], &a[j]);
			else
				break;
		}
		Swap(&a[i], &a[right - 1]);
		Qsort(a, left, i - 1);
		Qsort(a, i + 1, right);
	}
	else
		Insert_sorting(a + left, right - left + 1);
}

void Quick_sorting(ElementType a[], int size)
{
	Qsort(a, 0, size - 1);
}