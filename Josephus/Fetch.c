#if(0)
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#define FETCH 1000
#define RATE 0.0171
//迭代实现
//int main()
//{
//	
//	double a[49];
//	int i;
//	a[48] = 1000.0;
//
//	for (i = 47; i > 0; i--)
//	{
//		a[i] = (double)(a[i + 1] + 1000.0 / (1 + 0.172 / 12));
//	}
//	for (i = 48; i >0; i--)
//	{
//		printf("第%d月:%2f\n", i, a[i]);
//	}
//	system("pause");
//	return 0;
//}

//冒泡排序的核心是相邻元素两两比较进行交换。
//通过观察可以看到，如果第i个数后面的数的顺序都已经是有序,就不用再进行对比排序。所以，我们可以通过设置一个标记变量，标记数列中的数是否在循环结束前就已经排好序
void BubbleSort(int k[], int n)
{
	int i, j, temp, flag = 1,m;
	for (i = 0; i < n; i++)
	{
		if (flag)
		{
			flag = 0;
			//每一次由底至上地上升  
			for (j = n - 1; j > i; j--)
			{
				if (k[j - 1] > k[j])
				{
					temp = k[j - 1];
					k[j - 1] = k[j];
					k[j] = temp;
					flag = 1;
				}
			}
		}
		
		for ( m = 0; m < n; m++)
		{
			
			printf("%3d", k[m]);
		}
		printf("\n");
	}
}

void BubbleSort1(int k[], int n)
{
	int i, j, temp, flag = 1, m;
	for (i = 0; i < n; i++)
	{
		for (j = 1; j < n -i ; j++)
		{
			if (k[j - 1] > k[j])
			{
				temp = k[j - 1];
				k[j - 1] = k[j];
				k[j] = temp;
				flag = 1;
			}

		}

		for (m = 0; m < n; m++)
		{
			printf("%3d", k[m]);
		}
		printf("\n");
	}
}

//最简单的排序形式(不是冒泡排序)
//通过将下标为0的数（str[0]）与剩下其余9个数进行对比交换（将较少者放置在下标为0的位置上），就可以得到这10个数最小的那个
//10个数最小的那位确定后，接下来就要找剩下9个数最小的那个。
//因为已经确定出一个最小的数，所以就不要动str[0]，直接从str[1]开始，与剩下的8个数对比交换，找出9个数中最小的那位放到下标为1（str[1]）的位置上
//继续按照这个思路就可以将这十个数变成有序的（从小到大）的数组
//现在已经是选择排序了
void Sort(int k[], int n)
{
	int i, j, temp, m,l;
	for (i = 0; i < n; i++)
	{
		l = i;
		for (j = i+1; j < n; j++)
		{			
			if (k[j] < k[l])
			{
				l = j;							
			}
		}
		if(l!=i)
		{
			temp = k[l];
			k[l] = k[i];
			k[i] = temp;
		}
		

		for (m = 0; m < n; m++)
		{
			printf("%3d", k[m]);
		}
		printf("\n");
	}
}

int main()
{
	int i;//;a[10] = { 5, 2, 6, 0, 3, 9, 1, 7, 4, 8 };
	int a[10] = { 5, 2, 96, 0, 3, 9, 1, 7, 4, 8 };

	for (i = 0; i < 10; i++)
	{
		printf("%3d", a[i]);

	}
	printf("\n");
	Sort(a, 10);
	//BubbleSort1(a, 10);
	for (i = 0; i < 10; i++)
	{
		printf("%3d", a[i]);

	}
	printf("\n");
	system("pause");
	return 0;
}
#endif