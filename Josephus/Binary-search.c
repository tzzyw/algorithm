#if(0)
#define _CRT_SECURE_NO_DEPRECATE
#include "CriticalPath.h"  
#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
typedef struct {
	int number;
}elemType; //元素信息结构体 

typedef struct {
	elemType *elem;
	int length;
}SSTable; //总结构体


//创建表信息
void CreatStable(SSTable *ST, int length)
{
	int i;
	printf("请输入数据的个数:");
	scanf("%d", &ST->length);
	length = ST->length;
	ST->elem = (elemType *)malloc(length * sizeof(elemType));
	printf("请从小到大输入数据:\n");
	for (i = 0; i < ST->length; i++)
	{
		printf("请你输入一个整数 :");
		scanf("%d", &ST->elem[i].number);

	}
}
//比较函数
int EQ(int num1, int num2)
{
	if (num1 == num2)
	{
		return 1;
	}		
	else
	{
		return 0;
	}		
}

int LT(int num1, int num2)
{
	if (num1 < num2)
	{
		return 1;
	}		
	else
	{
		return 0;
	}		
}

//查找函数
int Search_Bin(SSTable *ST, int number)
{
	int low = 0, high = ST->length -1 ;
	int mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (EQ(ST->elem[mid].number, number))
		{
			return mid;
		}				
		else if (LT(number, ST->elem[mid].number))
		{
			high = mid - 1;
		}			
		else
		{
			low = mid + 1;
		}			
	}
	return -1;
}

//主函数
int main()
{
	int length = 0, number,result;
	SSTable ST;
	CreatStable(&ST, length);
	printf("输入你想要找的数:");
	scanf("%d", &number);
	result = Search_Bin(&ST, number);

	if (result >=0)
	{
		printf("找到数据%d\n", ST.elem[result]);
	}		
	else
	{
		printf("没有找到\n");
	}		

	system("pause");
	return 0;
}
#endif