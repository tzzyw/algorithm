#if(0)
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include<math.h>
#define MAX 100
int  Search_Seq(int array[], int n, int k)/*在数组中查找下标元素的值是k*/
{
	int  i = 0;
	array[n] = k;
	while (array[i] != k) i++;
	if (i<n) return i;
	else return -1;
}             //顺序查找
double length(int n)
{
	int i, sum = 0;
	double ave;
	for (i = 0; i <= n; i++)
	{
		sum = sum + i;
	}
	ave = sum / n;
	return i;
}

void bubble(int *p, int n)  //改进的地方
{
	int i, j, temp;          /*先排序*/
	for (i = 0; i<n - 1; i++)
	{
		for (j = 0; j<n - i - 1; j++)
		{
			if (p[j]>p[j + 1])
			{
				temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}
}
double loga(double n, double base)
{
	return log(n) / log(base);
}
int Search_Bin(int array[], int n, int key)/*在数组中查找关键字长度是n的元素,如果找到返回他的地址,else返回-1*/
{
	int l, r, mid;
	l = 0;
	r = n - 1;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (key == array[mid])
			return mid;   /*找到了返回地址*/
		else if (key<array[mid])
			r = mid - 1;
		else l = mid + 1;
	}
	return -1;
}       //折半查找

int Search_Blk(int array[], int n, int k)
{
	int i, j;
	for (i = 3; i<MAX; i += 4)
	{
		if (k == array[i])
		{
			printf("第%d个数为%d", i, k);
			return 1;
		}
		else if (k<array[i])
		{
			for (j = i - 3; j<i; j++)
			{
				if (k == array[j])
				{
					// printf("第%d个数为%d",j,k);
					return 1;
				}
			}
			break;
		}
	}//分块查找
}

void main()
{
	int i, k, m, n, result;
	double ave;
	int array[MAX];
	printf("输入数字个数:\n");
	scanf("%d", &n);
	printf("输入数字的值:\n");
	for (i = 0; i<n; i++)
		scanf("%d", &array[i]);
	printf("输入想查找的数字:");
	scanf("%d", &k);
	printf("输入查找方式1 顺序查找，2 折半查找，3 分块查找:");
	scanf("%d", &m);
	switch (m)
	{
	case 1:
		printf("      顺序查找!\n");
		result = Search_Seq(array, n, k);
		if (result >= 0)
		{
			printf("所要查找的数位于第%d位!\n", result + 1);
			ave = length(n);
			printf("平均查找长度为%f", ave);
		}
		else
			printf("      查找失败!\n");
		break;
	case 2:
		bubble(array, n);
		for (i = 0; i<n; i++)   //这里如果是<=到i=n最后一个数是随机显示的垃圾数  
		{
			printf(" %d", array[i]);
			if ((i + 1) % 5 == 0)
				printf("\n");
		}
		printf("      折半查找!\n");
		result = Search_Bin(array, n, k);
		if (result >= 0)
		{
			printf("所要查找的数位于第%d位!\n", result + 1);
			ave = loga(n + 1, 2) - 1;
			printf("平均查找长度为%f", ave);
		}
		else
			printf("      查找失败!\n");
		break;
	case 3:
		bubble(array, n);
		for (i = 0; i<n; i++)
		{
			printf(" %d", array[i]);
			if ((i + 1) % 5 == 0)
				printf("\n");
		}
		printf("      分块查找!\n");
		result = Search_Blk(array, n, k);
		if (result >= 0)
			printf("所要查找的数位于第%d位!\n", result + 1);
		else
			printf("      查找失败!\n");
		//  printf("      分块查找!\n");
		result = Search_Blk(array, n, k);
		break;
	default:
		printf("1 顺序查找，2 折半查找，3 分块查找!\n");
		return;
	}

	system("pause");
}

#endif