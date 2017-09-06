#if(0)
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

#define MAXSIZE 100

void Merge(int *list1, int list1Size, int *list2, int list2Size)
{
	//i数组1的下标,j数组2的下标,k为临时数组的下标
	int i, j, k,m;
	int temp[MAXSIZE];

	i = k = j = 0;
	while (i<list1Size && j< list2Size)
	{
		if (list1[i] < list2[j])
		{
			temp[k++] = list1[i++];
		}
		else
		{
			temp[k++] = list2[j++];
		}
	}
	//说明数组1的元素有剩余,把剩下的拷贝到临时数组中
	while (i<list1Size)
	{
		temp[k++] = list1[i++];
	}
	//说明数组2的元素有剩余,把剩下的拷贝到临时数组中
	while (j<list2Size)
	{
		temp[k++] = list2[j++];
	}
	//从数组1的起始地址开始到数组2的结束地址位置,把临时数组中排好序的元素拷贝到数组1中
	for (m = 0; m < (list1Size + list2Size); m++)
	{
		list1[m] = temp[m];
	}
}

void MergeSort(int a[], int n)
{
	if (n > 1)
	{
		int *list1 = a;
		int list1Size = n / 2;
		int *list2 = a + n / 2;
		int list2Size = n - list1Size;

		MergeSort(list1, list1Size);
		MergeSort(list2, list2Size);

		Merge(list1, list1Size, list2, list2Size);
	}	
}

//递归实现
int main()
{
	int i;//;a[10] = { 5, 2, 6, 0, 3, 9, 1, 7, 4, 8 };
	int a[10] = { 5, 2, 6, 0, 3, 9, 1, 7, 4, 8 };
	//int a[10] = { 1, 0, 2, 3, 4, 5, 6, 7, 8, 9 };
	MergeSort(a, 10);

	for (i = 0; i < 10; i++)
	{
		printf("%d", a[i]);

	}

	system("pause");
	return 0;
}
#endif