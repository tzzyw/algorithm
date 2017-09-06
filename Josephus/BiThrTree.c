#if(0)
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

//线索存储标志位 
//Link(0) 表示指向左右孩子的指针
//Link(1) 表示指向前驱后继的线索
typedef enum {Link,Thread} PointerTag;

typedef struct BiThrNode
{
	char data;
	struct BiThrNode *lchild, *rchild;
	PointerTag ltag;
	PointerTag rtag;

}BiThrNode, *BiThrTree;

//全局变量,始终指向刚刚访问过的结点
BiThrTree pre;

int num = 0;
//创建一课二叉树,约定用户遵照先序遍历方式输入数据
void CreateBiTree(BiThrTree *T)
{

	char c;
	scanf("%c", &c);

	printf("第%d :%c\n", num++, c);

	if (' ' == c)
	{
		*T = NULL;

	}
	else
	{
		*T = (BiThrNode*)malloc(sizeof(BiThrNode));

		(*T)->data = c;
		(*T)->ltag = Link;
		(*T)->rtag = Link;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}
}
//中序遍历线索化
void InThreading(BiThrTree T)
{
	if (T)
	{
		//递归左孩子线索化
		InThreading(T->lchild);

		//如果该结点没有左孩子设置ltag为Thread,并把lchild指向刚刚访问的结点
		if (!T->lchild)
		{
			T->ltag = Thread;
			T->lchild = pre;
		}	

		if (!pre->rchild)
		{
			pre->rtag = Thread;
			pre->rchild = T;
		}

		pre = T;

		//递归右孩子线索化
		InThreading(T->rchild);
	}
}

void InOrderThreading(BiThrTree *p, BiThrTree T)
{
	*p = (BiThrTree*)malloc(sizeof(BiThrNode));
	(*p)->ltag = Link;
	(*p)->rtag = Thread;
	(*p)->rchild = *p;
	if (!T)
	{
		(*p)->lchild = *p;
	}
	else
	{
		(*p)->lchild = T;
		pre = *p;

		InThreading(T);
		pre->rchild = *p;
		pre->rtag = Thread;
		(*p)->rchild = pre;
	}
}

void Visit(char c)
{
	printf("%c", c);
}

//中序遍历二叉树,非递归
void InOrderTraverse(BiThrTree T)
{
	BiThrTree p;
	p = T->lchild;

	while (p!=T)
	{
		while (p->ltag == Link)
		{
			p = p->lchild;
		}

		Visit(p->data);

		while (p->rtag == Thread && p->rchild !=T)
		{
			p = p->rchild;
			Visit(p->data);
		}

		p = p->rchild;
	}
}

int main()
{
	BiThrTree p, T = NULL;

	CreateBiTree(&T);

	InOrderThreading(&p,T);

	printf("中序遍历输出结果为:");

	InOrderTraverse(p);
	printf("\n");
	system("pause");
	return 0;
}

#endif