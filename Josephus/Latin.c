#if(0)
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}sqlist, *linklsit;


//循环链表的生成
linklsit CreateLinkList(int Number)
{
	linklsit head = NULL;
	linklsit s, r;
	int i;

	r = head;

	for (i = 1; i <= Number; i++)
	{
		s = (linklsit)malloc(sizeof(sqlist));
		s->data = i;

		if (head == NULL)
		{
			head = s;
		}			
		else
		{
			r->next = s;
		}			
		r = s;             //保持r在尾端
	}

	r->next = head;

	return head;
}

int main()
{
	linklsit p, r;
	int number, i, j;

	printf("请输入Latin矩阵的宽度： ");
	scanf("%d", &number);
	printf("\n %d维的Latin矩阵为：\n\n", number);

	p = CreateLinkList(number);
	r = p;

	for (i = 0; i<number; i++)
	{
		for (j = 0; j<number; j++)
		{
			printf("%3d", r->data);
			r = r->next;
		}
		printf("\n");
		p = p->next;
		r = p;
	}
	printf("\n");

	system("pause");

	return 0;
}

#endif