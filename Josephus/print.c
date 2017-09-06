#if(0)
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

void print()
{
	char c;
	scanf("%c", &c);

	if (c != '#')
	{
		print();
	}

	if (c != '#')
	{
		printf("%c", c);
	}
}

int count = 0;

//row 行 j 列
int notDanger(int row, int j, int(*chess)[8])
{
	int i, k, flag0 = 0, flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0, flag5 = 0;

	//判断行方向
	for (i = row, k = j ; k < 8; k++)
	{
		if (*(*(chess + i) + k) != 0)
		{
			flag0 = 1;
			break;
		}
	}

	//判断列方向
	for (i = 0; i < 8; i++)
	{
		if (*(*(chess + i) + j) != 0)
		{
			flag1 = 1;
			break;
		}
	}

	//判断左上方
	for (i = row, k = j; i >= 0 && k >= 0; i--, k--)
	{
		if (*(*(chess + i) + k) != 0)
		{
			flag2 = 1;
			break;
		}
	}

	//判断右下方
	for (i = row, k = j; i < 8 && k < 8; i++, k++)
	{
		if (*(*(chess + i) + k) != 0)
		{
			flag3 = 1;
			break;
		}
	}

	//判断右上方
	for (i = row, k = j; i >= 0 && k < 8; i--, k++)
	{
		if (*(*(chess + i) + k) != 0)
		{
			flag4 = 1;
			break;
		}
	}

	//判断左下方
	for (i = row, k = j; i < 8 && k >= 0; i++, k--)
	{
		if (*(*(chess + i) + k) != 0)
		{
			flag5 = 1;
			break;
		}
	}

	if (flag0 || flag1 || flag2 || flag3 || flag4 || flag5)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

//row 表示起始行 n 表示列数 int(*chess)[8] 表示指向棋盘每一行的指针
void EightQueen(int row, int n, int(*chess)[8])
{
	int chess2[8][8], i, j;

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			chess2[i][j] = chess[i][j];
		}
	}

	if (8 == row)
	{
		printf("第 %d 种\n", count + 1);
		for (i = 0; i < 8; i++)
		{
			for (j = 0; j < 8; j++)
			{
				printf("%d ", *(*(chess2 + i) + j));
			}
			printf("\n");
		}
		printf("\n");
		count++;
		if (count == 8)
		{
			system("pause");
		}
	}
	else
	{
		//判断这个位置是否有危险
		//如果没有危险 继续往下  j代表列
		for (j = 0; j < n; j++)
		{
			//判断是否危险
			if (notDanger(row, j, chess))
			{
				for (i = 0; i < 8; i++)
				{
					*(*(chess2 + row) + i) = 0;
				}
				*(*(chess2 + row) + j) = 1;

				EightQueen(row + 1, n, chess2);
			}
		}
	}
}
//8皇后问题
void main()
{
	int chess[8][8], i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			chess[i][j] = 0;
		}
	}

	EightQueen(0, 8, chess);

	printf("总共有 %d 种解决方法\n\n", count);

	//print();

	int u = 10;
	int *p = &u;
	//方括号可以对指针进行操作
	printf("%d", p[0]);
	printf("%d", p[1]);

	system("pause");
	return 0;
}

#endif