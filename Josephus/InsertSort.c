#if(0)
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

//第一个数字默认是排好序的,从第二个数字开始(设定为temp)依次和前面的数字比较如果小于前面的数字就将前面的数字往后移动一位
//直到找到比要temp小的第一个数组元素,将temp插入到这个数字后面的数字后移留出的空位置

void InsertSort(int a[], int n)
{
	int i, j, temp;
	for (i = 1; i < n ; i++)
	{
		temp = a[i];
		j = i;

		while (j >0 && temp < a[j-1])
		{
			//比temp大的所有数字往后移一位
			a[j] = a[j - 1];
			j--;
		}
		//把temp插入到第一个比temp小的数后面
		a[j] = temp;

		//if (a[i] < a[i - 1])
		//{
		//	temp = a[i];
		//	j = i - 1;
		//	//大于temp的从数组的前面已经排序的序列中依次往后移动第一个移动的是a[i]前面的数据移动到a[i]的位置
		//	//一直移动到不大于temp的那个位置,移动产生的位置将temp放入,这样就将未排序的数据插入到了前面的一排序的序列中.
		//	while ( j>=0 && a[j] > temp)
		//	{
		//		a[j + 1] = a[j];
		//		j--;
		//	}
		//	a[j + 1] = temp;
		//	/*for (j = i-1; a[j] > temp; j--)
		//	{
		//		a[j + 1] = a[j];
		//	}
		//	a[j + 1] = temp;*/
		//}		
	}
}
int main()
{
	int i;//;a[10] = { 5, 2, 6, 0, 3, 9, 1, 7, 4, 8 };
	int a[10] = { 5, 2, 6, 0, 3, 9, 1, 7, 4, 8 };
	//int a[10] = { 1, 0, 2, 3, 4, 5, 6, 7, 8, 9 };
	InsertSort(a, 10);

	for (i = 0; i < 10; i++)
	{
		printf("%d", a[i]);

	}

	system("pause");
	return 0;
}
#endif