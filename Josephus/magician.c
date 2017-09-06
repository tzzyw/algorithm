#if(0)
#include <stdio.h>
#include <stdlib.h>

#define CardNumber 13

typedef struct node
{
	int data;
	struct node *next;
}sqlist, *linklist;

linklist CreateLinkList()
{
	linklist head = NULL;
	linklist s, r;
	int i;

	r = head;

	for (i = 1; i <= CardNumber; i++)
	{
		s = (linklist)malloc(sizeof(sqlist));
		s->data = 0;		//初始化为0

		if (head == NULL)
		{
			head = s;
		}
		else
		{
			r->next = s;
		}			
		r = s;
	}
	r->next = head;
	return head;

}

//发牌顺序计算
void Magician(linklist head)
{
	linklist p;
	int j;
	int countnumber = 2;					//表示牌的点数

	p = head;
	p->data = 1;

	while (1)
	{
		for (j = 0; j<countnumber; j++)
		{
			p = p->next;
			if (p->data != 0)			//关键点
			{
				//p->next;				
				j--;
			}
		}

		if (p->data == 0)					/*0表示该位置还未放置牌*/
		{
			p->data = countnumber;
			countnumber++;

			if (countnumber == 14)
			{
				break;//跳出一层循环
			}
						
		}
	}
}

//销毁工作(可不写)
void DestoryList(linklist * list)
{
	linklist ptr = *list;
	linklist buff[CardNumber];
	int i = 0;

	while (i<CardNumber)
	{
		buff[i++] = ptr;
		ptr = ptr->next;
	}

	for (i = 0; i<CardNumber; i++)
	{
		free(buff[i]);
	}

	*list = 0;
}

int main()
{
	linklist p;
	int i;

	p = CreateLinkList();
	Magician(p);

	printf("按如下顺序排列：\n");
	for (i = 0; i<CardNumber; i++)
	{
		printf("黑桃%d ", p->data);
		p = p->next;
	}

	DestoryList(&p);

	system("pause");

	return 0;
}

#endif