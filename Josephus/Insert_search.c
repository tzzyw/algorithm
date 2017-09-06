#if(0)
#define _CRT_SECURE_NO_DEPRECATE
#include "CriticalPath.h"  
#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>

//参数a:数组的指针,key:要查找的值,n:数组的长度
int Insert_search(int *a, int key, int n)
{
	int low, high, mid;
	low = 0;
	high = n - 1;
	while (low <= high)
	{
		mid = low + (high - low) * (key - a[low]) / (a[high] - a[low]); //此处于二分查找不同,套用插值公式  
		if (a[mid] > key)         //如果key比插值小,把高位调整为插值下标的下一位    
		{
			high = mid - 1;
		}			
		else if (a[mid] < key)
		{
			low = mid + 1;
		}			
		else
		{
			return mid;
		}			
	}
	return -1;
}

//差值查找,在折半查找的基础上直接套用差值公式: mid = low + (high - low) * (key - a[low]) / (a[high] - a[low]);
int main()
{
	int a[] = { 1, 5, 17, 25, 33, 38, 46, 55, 69, 75, 99 };
	int key;
	int len = sizeof(a) / sizeof(*a);
	printf("请输入要查找的值:\n");
	scanf("%d", &key);
	int pos = Insert_search(a, key, len);
	if (pos != -1)
	{
		printf("在数组的第%d个位置找到元素:%d\n", pos + 1, key);
	}		
	else
	{
		printf("未在数组中找到元素:%d\n", key);
	}
	system("pause");
	return 0;
}
#endif