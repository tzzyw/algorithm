#if(0)
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int ElemType;

typedef struct Node
{
	ElemType data;
	struct Node *next;

}Node, *LinkList;

//初始化带头结点的空链表
Status InitList(LinkList *L)
{
	*L = (LinkList)malloc(sizeof(Node));

	if (!(*L))
	{
		return ERROR;
	}

	(*L)->next = NULL;

	return OK;
}

//返回L中数据元素个数
int ListLength(LinkList L)
{
	int i = 0;
	LinkList p = L->next;

	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}

//随机产生n个元素的值,建立带表头结点的单链表L(头插法)
void CreateListHead(LinkList *L, int n)
{
	LinkList p = NULL;
	int i;
	//初始化随机数种子
	srand(time(0));

	//建立一个带头结点的单链表
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;

	for (i = 0; i < n; i++)
	{
		//生成新结点
		p = (LinkList)malloc(sizeof(Node));
		//100以内的随机数
		p->data = rand() % 100 + 1;
		//插入到表头
		p->next = (*L)->next;
		(*L)->next = p;
	}

	p->next = (*L)->next;
	(*L)->next = p;
}

//随机产生n个元素的值,建立带表头结点的单链表L(尾插法)
void CreateListTail(LinkList *L, int n)
{
	LinkList p, r;
	int i;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));
	r = *L;

	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand() % 100 + 1;
		r->next = p;
		r = p;
	}

	r->next = (*L)->next->next;
}

//比较步数的方法
int HasLoop1(LinkList L)
{
	LinkList cur1 = L;
	int pos1 = 0;

	while (cur1)
	{
		LinkList cur2 = L;
		int pos2 = 0;
		while (cur2)
		{
			if (cur2 == cur1)
			{
				if (pos1 == pos2)
				{
					break;
				}
				else
				{
					printf("环的位置在第%d个结点处\n\n", pos2);
					return 1;
				}
			}
			cur2 = cur2->next;
			pos2++;

		}
		cur1 = cur1->next;
		pos1++;
	}

	return 0;
}

//利用快慢针的方法
int HasLoop2(LinkList L)
{
	int stept1 = 1;
	int stept2 = 2;
	LinkList p = L;
	LinkList q = L;

	while (p!=NULL && q !=NULL && q->next != NULL)
	{
		p = p->next;
		if (q->next != NULL)
		{
			q = q->next->next;
		}
		printf("p:%d q:%d \n", p->data, q->data);

		if (p == q)
		{
			return 1;
		}
	}

	return 0;
}
//判断链表中是否有环
int main()
{
	LinkList L;
	Status i;
	char opp = 'z';
	ElemType e;
	int find;
	int tmp;

	i = InitList(&L);
	printf("\n1.创建有环链表(尾插法) \n2.创建无环链表(头插法) \n3.判断链表是否有环 \n0.退出 \n\r");

	while (opp!='0')
	{
		scanf("%c", &opp);
		switch (opp)
		{
		case '1':
			CreateListTail(&L, 10);
			printf("成功创建有环链表L(尾插法)\n\n");
			break;
		case '2':
			CreateListHead(&L, 10);
			printf("成功创建无环链表L(头插法)\n\n");
			break;

		case '3':
			printf("方法一:\n\n");
			if (HasLoop1(L))
			{
				printf("结论:链表有环\n\n");
			}
			else
			{
				printf("结论:链表无环\n\n");
			}

			printf("方法二:\n\n");
			if (HasLoop2(L))
			{
				printf("结论:链表有环\n\n");
			}
			else
			{
				printf("结论:链表无环\n\n");
			}
			break;

		case '0':
			exit(0);

		}
	}
}
#endif