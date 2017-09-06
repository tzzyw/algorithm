#if(0)
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10
#define MAXBUFFER 10

//这个逆波兰计算器用
//typedef double elementType;
//这个求后缀表达式用
typedef char elementType;
typedef struct
{
	elementType *base;
	elementType * top;
	int stackSize;
}sqStack;

void InitStack(sqStack *s)
{
	s->base = (elementType*)malloc(sizeof(elementType)* STACK_INIT_SIZE);
	if (!s)
	{
		exit(0);
	}

	s->top = s->base;
	s->stackSize = STACK_INIT_SIZE;
}

void Push(sqStack *s, elementType e)
{
	//栈满追加空间
	if (s->top - s->base >= s->stackSize)
	{
		s->base = (elementType*)realloc(s->base, (s->stackSize + sizeof(elementType)* STACKINCREMENT));
		if (!s)
		{
			exit(0);
		}

		s->top = (s->base + s->stackSize);
		s->stackSize = s->stackSize + STACKINCREMENT;
	}

	*(s->top) = e;
	s->top++;
}

void Pop(sqStack *s, elementType *e)
{
	if (s->top == s->base)
	{
		return;
	}

	*e = *(--s->top);
}

int StackLen(sqStack s)
{
	return (s.top - s.base);
}


int main()
{
	sqStack s;
	char c,e;
	InitStack(&s);
	printf("请输入中缀表达式,以#结束:\n");
	scanf("%c", &c);

	while (c != '#')
	{
		while (c >= '0'&& c <='9')
		{
			printf("%c", c);
			scanf("%c", &c);
			if (c < '0' || c>'9')
			{
				printf(" ");
			}
		}
		
		if (')' == c)
		{
			Pop(&s, &e);
			while ('(' != e)
			{
				printf("%c ", e);
				Pop(&s, &e);
			}

		}
		else if ('+' == c || '-'==c)
		{
			if (!StackLen(s))
			{
				Push(&s, c);
			}
			else
			{
				do
				{
					Pop(&s, &e);
					if ('(' == e)
					{
						Push(&s, e);
					}
					else
					{
						printf("%c ", e);
					}
				} while (StackLen(s) && '('!=e);

				Push(&s, c);
			}
		}
		else if ('*' == c || '/' == c || '(' == c )
		{
			Push(&s, c);
		}
		else if ('#' == c)
		{
			break;
		}
		else
		{
			printf("出错:");
		}
		scanf("%c", &c);
	}

	while (StackLen(s))
	{
		Pop(&s, &e);
		printf("%c ", e);
	}

	/*
	////逆波兰计算器
	sqStack s;
	char c;
	double d, e;
	char str[MAXBUFFER];
	int i = 0;

	InitStack(&s);
	printf("请按逆波兰表达式输入待计算数据,数据与运算符应空格隔开,以#结束:\n");

	scanf("%c", &c);

	while (c!='#')
	{
		while (isdigit(c) || c == '.')
		{
			str[i++] = c;
			str[i] = '\0';
			if (i >= 10)
			{
				printf("\n出错:输入的单个数据过大! \n");
				return -1;
			}

			scanf("%c", &c);

			if (c == ' ')
			{
				d = atof(str);
				Push(&s, d);
				i = 0;
				break;
			}
		}

		switch (c)
		{
		case '+':
			Pop(&s,&e);
			Pop(&s, &d);
			Push(&s, d + e);
			break;	
		case '-':
			Pop(&s, &e);
			Pop(&s, &d);
			Push(&s, d - e);
			break;
		case '*':
			Pop(&s, &e);
			Pop(&s, &d);
			Push(&s, d * e);
			break;
		case '/':
			Pop(&s, &e);
			Pop(&s, &d);
			if (e != 0)
			{
				Push(&s, d / e);

			}
			else
			{
				printf("\n出错:除数为零! \n");
			}
			break;
		}

		scanf("%c", &c);
	}
	Pop(&s, &d);
	printf("\n计算结果为: %f! \n", d);
	*/
	
	system("pause");
	return 0;
}

#endif