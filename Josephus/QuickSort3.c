#if(0)
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10

int Partition(int a[], int low, int high)
{
	int point, temp;
	point = a[low];

	while (low < high)
	{
		while (low < high && a[high] >= point)
		{
			high--;
		}

		a[low] = a[high];

		while (low<high && a[low] <= point)
		{
			low++;
		}

		a[high] = a[low];
	}

	a[low] = point;

	return low;
}


void QuickSort(int a[], int low, int high)
{
	int point;
	if (low < high)
	{
		point = Partition(a, low, high);
		QuickSort(a, low, point - 1);
		QuickSort(a, point + 1, high);
	}
}


//µü´úÊµÏÖ
int main()
{
	int i;//;a[10] = { 5, 2, 6, 0, 3, 9, 1, 7, 4, 8 };
	int a[10] = { 5, 2, 6, 0, 3, 9, 1, 7, 4, 8 };
	//int a[10] = { 1, 0, 2, 3, 4, 5, 6, 7, 8, 9 };
	QuickSort(a, 0, 9);

	for (i = 0; i < 10; i++)
	{
		printf("%d", a[i]);

	}

	system("pause");
	return 0;
}
#endif