#if(0)
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

//这个是普通的排序不是冒泡排序,因为不是两两比对,是以第i个数和后面的树依次比对,效率并不高
//void BubbleSort(int k[], int n)
//{
//	int i, j, temp;
//	for ( i = 0; i < n-1; i++)
//	{
//		for (j = i+1; j < n; j++)
//		{
//			if (k[i] > k[j])
//			{
//				temp = k[j];
//				k[j] = k[i];
//				k[i] = temp;
//			}
//		}
//	}
//}
//
//void BubbleSort(int k[], int n)
//{
//	int i, j, temp, flag = 1;
//	for (i = 0; i < n; i++)
//	{
//		for (j = i + 1; j < n; j++)
//		{		
//			if (k[i] > k[j])
//			{
//				temp = k[i];
//				k[i] = k[j];
//				k[j] = temp;				
//			}
//		}
//
//	}
//}



//冒泡排序的核心是相邻元素两两比较进行交换。
//通过观察可以看到，如果第i个数后面的数的顺序都已经是有序,就不用再进行对比排序。所以，我们可以通过设置一个标记变量，标记数列中的数是否在循环结束前就已经排好序
//void BubbleSort(int k[], int n)
//{
//	int i, j, temp, flag = 1,m;
//	for (i = 0; i < n; i++)
//	{
//		if (flag)
//		{
//			flag = 0;
//			//每一次由底至上地上升  
//			for (j = n - 1; j > i; j--)
//			{
//				if (k[j - 1] > k[j])
//				{
//					temp = k[j - 1];
//					k[j - 1] = k[j];
//					k[j] = temp;
//					flag = 1;
//				}
//			}
//		}
//
//		for ( m = 0; m < n; m++)
//		{
//
//			printf("%3d", k[m]);
//		}
//		printf("\n");
//	}
//}
//最简单的排序形式(不是冒泡排序)
//通过将下标为0的数（str[0]）与剩下其余9个数进行对比交换（将较少者放置在下标为0的位置上），就可以得到这10个数最小的那个
//10个数最小的那位确定后，接下来就要找剩下9个数最小的那个。
//因为已经确定出一个最小的数，所以就不要动str[0]，直接从str[1]开始，与剩下的8个数对比交换，找出9个数中最小的那位放到下标为1（str[1]）的位置上
//继续按照这个思路就可以将这十个数变成有序的（从小到大）的数组
//void Sort(int k[], int n)
//{
//	int i, j, temp, m;
//	for (i = 0; i < n; i++)
//	{
//		for (j = i + 1; j < n; j++)
//		{
//			//大数往后交换
//			if (k[j] < k[i])
//			{
//				temp = k[i];
//				k[i] = k[j];
//				k[j] = temp;				
//			}
//
//		}
//
//		for (m = 0; m < n; m++)
//		{
//			printf("%3d", k[m]);
//		}
//		printf("\n");
//	}
//}

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

//int main()
//{
//	int i, a[10] = {5,2,6,0,3,9,1,7,4,8};
//	BubbleSort(a, 10);
//
//	for ( i = 0; i < 10; i++)
//	{
//		printf("%d", a[i]);
//
//	}
//
//	system("pause");
//	return 0;
//}


void BubbleSort(int k[], int n)
{
	int i, j, temp, flag = 1;
	for ( i = 0; i < n-1; i++)
	{
		if (flag == 1)
		{
			for (j = n - 1; j > i; j--)
			{
				flag = 0;
				//前一个和后一个两两比较 如果没有发生移动说明后面的都是已经排好序的 k[j - 1] > k[j] 不会再成立
				if (k[j - 1] > k[j])
				{
					temp = k[j - 1];
					k[j - 1] = k[j];
					k[j] = temp;
					flag = 1;
				}
			}
		}		
	}
}

int main()
{
	int i;//;a[10] = { 5, 2, 6, 0, 3, 9, 1, 7, 4, 8 };
	int a[10] = { 1, 0, 2, 3, 4, 5, 6, 7, 8, 9 };
	BubbleSort(a, 10);

	for ( i = 0; i < 10; i++)
	{
		printf("%d", a[i]);

	}

	system("pause");
	return 0;
}


#endif