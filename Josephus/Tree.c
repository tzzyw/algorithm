#if(0)
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

#define MAX_TREE_SIZE 100
typedef char ElemType;

//孩子结点
typedef struct CTNode
{
	//孩子结点的下标
	int child;
	//指向下一个孩子结点的指针
	struct CTNode *next;
}*Childptr;

//表头结构
typedef struct
{
	//存放在树中的结点数据
	ElemType data;
	//存放双亲的下标
	int parent;
	//指向第一个孩子的指针
	Childptr firstchild;

}CTBox;

//树结构

typedef struct
{
	//结点数组
	CTBox nodes[MAX_TREE_SIZE];
	//r根的位置n结点个数
	int r, n;
};

#endif