#if(0)
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10

int Partition(int a[], int low, int high)
{
	int point,temp;
	point = a[low];

	while (low < high)
	{
		//从后面往前找,找到第一个比基准数大的数和基准数交换位置
		while (low < high && a[high] >= point)
		{
			high--;
		}

		temp = a[low];
		a[low] = a[high];
		a[high] = temp;

		//从前面往后找,找到第一个比基准数小的数,和基准数交换位置
		while (low<high && a[low] <= point)
		{
			low++;
		}

		temp = a[low];
		a[low] = a[high];
		a[high] = temp;
	}
	//返回当前基准数的位置
	return low;
}
   

void QuickSort(int a[], int low,int high)
{
	int point;
	if (low < high)
	{
		//找到第一个基准数进行完一次移动后的位置(比基准数大的数移动到后面,比基准数小的数移动到前面)
		point = Partition(a, low, high);
		//然后以当前基准数的位置把整个数组分成两部分再次进行基准数的查找交换位置(比基准数大的数移动到后面,比基准数小的数移动到前面)
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