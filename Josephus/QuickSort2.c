#if(0)
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10

int Partition(int a[], int low, int high)
{
	int point, temp;
	//m为中间位置
	int m = low + (high - low) / 2;

	//低位大于高位交换较大的数交换到高位
	if (a[low] > a[high])
	{
		temp = a[low];
		a[low] = a[high];
		a[high] = temp;
	}
	//中间位置大于高位较大的数换到高位
	if (a[m] > a[high])
	{
		temp = a[low];
		a[low] = a[high];
		a[high] = temp;
	}
	//经过上面的两步高位的已经是最大的数了,如果中间的数比低位大交换,确保三个数中的中间的那个数在low低位上面
	if (a[m] > a[low])
	{
		temp = a[low];
		a[low] = a[high];
		a[high] = temp;
	}

	point = a[low];

	while (low < high)
	{
		while (low < high && a[high] >= point)
		{
			high--;
		}

		temp = a[low];
		a[low] = a[high];
		a[high] = temp;

		while (low<high && a[low] <= point)
		{
			low++;
		}

		temp = a[low];
		a[low] = a[high];
		a[high] = temp;
	}

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


//迭代实现
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