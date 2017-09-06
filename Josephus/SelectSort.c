#if(0)
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

void SelectSort(int a[], int n)
{
	int i, j, min, temp;
	for (i = 0; i < n-1; i++)
	{
		min = i;
		for (j = i+1; j < n; j++)
		{			
			if (a[j] < a[i])
			{
				min = j;
			}
		}

		if (min != i)
		{
			temp = a[min];
			a[min] = a[i];
			a[i] = temp;
		}
	}
}
int main()
{
	int i;//;a[10] = { 5, 2, 6, 0, 3, 9, 1, 7, 4, 8 };
	int a[10] = { 1, 0, 2, 3, 4, 5, 6, 7, 8, 9 };
	SelectSort(a, 10);

	for (i = 0; i < 10; i++)
	{
		printf("%d", a[i]);

	}

	system("pause");
	return 0;
}
#endif