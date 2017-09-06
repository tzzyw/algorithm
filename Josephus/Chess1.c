#if(0)
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <time.h>

#define X 8
#define Y 8

int chess[X][Y];
int num = 0;
//找到基于(x,y)位置的下一个可走的位置
int nextxy(int *x, int *y, int count)
{
	switch (count)
	{
	case 0:
		if (*x + 2 <= X - 1 && *y - 1 >= 0 && chess[*x + 2][*y - 1] == 0)
		{
			/**x += 2;
			*y -= 1;*/
			chess[*x + 2][*y - 1] = num++;
			//return 1;
		}
		break;
	case 1:
		if (*x + 2 <= X - 1 && *y + 1 <= Y - 1 && chess[*x + 2][*y + 1] == 0)
		{
		/*	*x += 2;
			*y += 1;*/
			chess[*x + 2][*y + 1] = num++;
			//return 1;
		}
		break;
	case 2:
		if (*x + 1 <= X - 1 && *y - 2 >= 0 && chess[*x + 1][*y - 2] == 0)
		{
			/**x = *x + 1;
			*y = *y - 2;*/
			chess[*x + 1][*y - 2] = num++;
			//return 1;
		}
		break;
	case 3:
		if (*x + 1 <= X - 1 && *y + 2 <= Y - 1 && chess[*x + 1][*y + 2] == 0)
		{
			/**x = *x + 1;
			*y = *y + 2;*/

			chess[*x + 1][*y + 2] = num++;
			//return 1;
		}
		break;
	case 4:
		if (*x - 2 >= 0 && *y - 1 >= 0 && chess[*x - 2][*y - 1] == 0)
		{
			/**x = *x - 2;
			*y = *y - 1;*/
			chess[*x - 2][*y - 1] = num++;
			//return 1;
		}
		break;
	case 5:
		if (*x - 2 >= 0 && *y + 1 <= Y - 1 && chess[*x - 2][*y + 1] == 0)
		{
			/**x = *x - 2;
			*y = *y + 1;*/
			chess[*x - 2][*y + 1] = num++;
			//return 1;
		}
		break;
	case 6:
		if (*x - 1 >= 0 && *y - 2 >= 0 && chess[*x - 1][*y - 2] == 0)
		{
			/**x = *x - 1;
			*y = *y - 2;*/
			chess[*x - 1][*y - 2] = num++;
			//return 1;
		}
		break;
	case 7:
		if (*x - 1 >= 0 && *y + 2 <= Y - 1 && chess[*x - 1][*y + 2] == 0)
		{
			/**x = *x - 1;
			*y = *y + 2;*/
			chess[*x - 1][*y + 2] = num++;
			//return 1;
		}
		break;
	default:
		break;
	}

	return 0;
}

void print()
{
	int i, j;
	for (i = 0; i < X; i++)
	{
		for (j = 0; j < Y; j++)
		{
			printf("%2d\t", chess[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
//深度优先遍历棋盘 (x,y)为位置坐标 tag 是标记变量,每走一步 tag+1
int TravelChessBoard(int x, int y, int tag)
{
	int x1 = x;
	int y1 = y;
	int flag = 0;
	int count = 0;
	chess[x][y] = tag;
	//printf("%d\n",tag);
	if (X*Y == tag)
	{
		//打印棋盘
		print();
		return 1;
	}

	flag = nextxy(&x1, &y1, count);

	while (0 == flag && count <7)
	{
		count++;
		flag = nextxy(&x1, &y1, count);
	}

	//找到马的下一个可走的坐标(x1,y1),如果找到flag = 1,否则为0
	while (flag)
	{
		if (TravelChessBoard(x1, y1, tag + 1))
		{
			return 1;
		}

		//找到马的下一个可走的坐标(x1,y1),如果找到flag = 1,否则为0
		x1 = x;
		y1 = y;
		count++;
		flag = nextxy(&x1, &y1, count);
		while (0 == flag && count <7)
		{
			count++;
			flag = nextxy(&x1, &y1, count);
		}
	}

	if (0 == flag)
	{
		chess[x][y] = 0;
	}

	return 0;
}

int main()
{
	int i, j,k;
	clock_t start, finish;
	start = clock();

	for (i = 0; i < X; i++)
	{
		for (j = 0; j < Y; j++)
		{
			chess[i][j] = 0;
		}
	}

	for (i = 0; i < X; i++)
	{
		for (j = 0; j < Y; j++)
		{
			int x1 = i;
			int y1 = j;
			for (k = 0; k < 8; k++)
			{
				nextxy(&x1, &y1, k);
			}			
		}
	}

	//if (!TravelChessBoard(2, 0, 1))
	//{
	//	printf("失败了\n");
	//}
	print();

	finish = clock();

	printf("供耗时: %f秒\n\n", (double)(finish - start) / CLOCKS_PER_SEC);
	system("pause");

	return 0;
}
#endif