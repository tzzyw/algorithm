#if(0)
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

//约瑟夫问题
//问题描述：n个人（编号1~n)，从1开始报数，报到m的退出，剩下的人继续从1开始报数。按顺序输出列者编号。
typedef struct node
{
	int data;
	struct node *next;
}node;

node *create(int n)
{
	node *p = NULL;
	node *head;
	node *s = NULL;
	//head是一个空的头结点并无数据,也不在环中
	head = (node*)malloc(sizeof(node));

	//p指向当前节点
	p = head;
	int i = 1;

	if (0 != n)
	{
		while (i<=n)
		{
			s = (node*)malloc(sizeof(node));
			s->data = i++;
			p->next = s;
			p = s;
		}
		s->next = head->next;
	}
	free(head);
	//返回指向链表的第一个结点的指针
	return s->next;
}

int main()
{
	int n = 41;
	int m = 3;
	int i;
	node *p = create(n);
	node *temp;

	m %= n;

	//当p == p->next时表示仅剩下一个链表结点了,循环执行直到最后一个结点
	while (p != p->next)
	{
		//从1开始报数，报到m的退出,指针移动到要删除结点的前一个结点
		for ( i = 1; i < m-1; i++)
		{
			p = p->next;
		}
		//p结点为要推出结点的前一个结点
		//打印要推出的结点
		printf("%d->", p->next->data);
		//临时变量指向要退出的结点
		temp = p->next;
		//p的下一个结点指向要退出结点的下一个结点,此时要退出的结点从链表中删除
		p->next = temp->next;

		//释放要退出的结点
		free(temp);

		//p指针往后移动以便上面的循环再循环m-1次到达下一个要删除的结点的前一个结点
		p = p->next;
	}

	printf("%d\n", p->data);

	
	system("pause");

	return 0;
}
#endif