#if(0)
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

typedef struct BiTNode
{
	char data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

int num = 0;
//创建一棵二叉树 约定用户按照先序遍历的方式输入数据
void CreateBiTree(BiTree *T)
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
		*T = (BiTNode*)malloc(sizeof(BiTNode));

		(*T)->data = c;
		//printf("左结点:%c\n", c);
		CreateBiTree(&(*T)->lchild);
		//printf("右结点:%c\n", c);
		CreateBiTree(&(*T)->rchild);
	}
}

//访问二叉树结点的具体操作
void Visit(char c, int level)
{
	printf("%c 位于第 %d 层\n", c, level);
}
//先序遍历二叉树
PreOrderTraverse(BiTree T, int level)
{
	if (T)
	{
		Visit(T->data, level);
		PreOrderTraverse(T->lchild, level + 1);
		PreOrderTraverse(T->rchild, level + 1);
	}
}

int main()
{
	int level = 1;
	BiTree T = NULL;

	CreateBiTree(&T);

	PreOrderTraverse(T, level);

	system("pause");
	return 0;
}

#endif