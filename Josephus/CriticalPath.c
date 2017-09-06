#if(0)
#define _CRT_SECURE_NO_DEPRECATE
#include "CriticalPath.h"  
#include <stdio.h>
#include <stdlib.h>
int *etv, *ltv; //事件最早发生时间和最迟发生时间数组  
int top2; //用于Stack2的指针  
int *Stack2; //用于存储拓扑序列的栈  
void CreateGraph(Graph *G) //创建图  
{
	EdgeNode *e = NULL;
	G->NumVertex = 10;
	G->NumEdge = 13;
	//初始化图
	for (int i = 0; i < G->NumVertex; ++i)
	{
		G->Vertex[i].data = i;
		G->Vertex[i].in = 0;
		G->Vertex[i].FirstEdge = NULL;
	}
	//顶点间的连接信息  
	e = (EdgeNode*)malloc(sizeof(EdgeNode)); //v0 -> v1 权值为3  
	e->next = G->Vertex[0].FirstEdge;
	e->AdjVex = 1;
	e->weight = 3;
	G->Vertex[0].FirstEdge = e;
	++G->Vertex[e->AdjVex].in;

	e = (EdgeNode*)malloc(sizeof(EdgeNode)); //v0 -> v2 权值为4  
	e->next = G->Vertex[0].FirstEdge;
	e->AdjVex = 2;
	e->weight = 4;
	G->Vertex[0].FirstEdge = e;
	++G->Vertex[e->AdjVex].in;

	e = (EdgeNode*)malloc(sizeof(EdgeNode)); //v1 -> v3 权值为5  
	e->next = G->Vertex[1].FirstEdge;
	e->AdjVex = 3;
	e->weight = 5;
	G->Vertex[1].FirstEdge = e;
	++G->Vertex[e->AdjVex].in;

	e = (EdgeNode*)malloc(sizeof(EdgeNode)); //v1 -> v4 权值为6  
	e->next = G->Vertex[1].FirstEdge;
	e->AdjVex = 4;
	e->weight = 6;
	G->Vertex[1].FirstEdge = e;
	++G->Vertex[e->AdjVex].in;

	e = (EdgeNode*)malloc(sizeof(EdgeNode)); //v2 -> v3 权值为8  
	e->next = G->Vertex[2].FirstEdge;
	e->AdjVex = 3;
	e->weight = 8;
	G->Vertex[2].FirstEdge = e;
	++G->Vertex[e->AdjVex].in;

	e = (EdgeNode*)malloc(sizeof(EdgeNode)); //v2 -> v5 权值为7  
	e->next = G->Vertex[2].FirstEdge;
	e->AdjVex = 5;
	e->weight = 7;
	G->Vertex[2].FirstEdge = e;
	++G->Vertex[e->AdjVex].in;

	e = (EdgeNode*)malloc(sizeof(EdgeNode)); //v3 -> v4 权值为3  
	e->next = G->Vertex[3].FirstEdge;
	e->AdjVex = 4;
	e->weight = 3;
	G->Vertex[3].FirstEdge = e;
	++G->Vertex[e->AdjVex].in;

	e = (EdgeNode*)malloc(sizeof(EdgeNode)); //v4 -> v6 权值为 9  
	e->next = G->Vertex[4].FirstEdge;
	e->AdjVex = 6;
	e->weight = 9;
	G->Vertex[4].FirstEdge = e;
	++G->Vertex[e->AdjVex].in;

	e = (EdgeNode*)malloc(sizeof(EdgeNode)); //v4 -> v7 权值 4  
	e->next = G->Vertex[4].FirstEdge;
	e->AdjVex = 7;
	e->weight = 4;
	G->Vertex[4].FirstEdge = e;
	++G->Vertex[e->AdjVex].in;

	e = (EdgeNode*)malloc(sizeof(EdgeNode)); //v5 -> v7 权值为6  
	e->next = G->Vertex[5].FirstEdge;
	e->AdjVex = 7;
	e->weight = 6;
	G->Vertex[5].FirstEdge = e;
	++G->Vertex[e->AdjVex].in;

	e = (EdgeNode*)malloc(sizeof(EdgeNode)); //v6 -> v9 权值为2  
	e->next = G->Vertex[6].FirstEdge;
	e->AdjVex = 9;
	e->weight = 2;
	G->Vertex[6].FirstEdge = e;
	++G->Vertex[e->AdjVex].in;

	e = (EdgeNode*)malloc(sizeof(EdgeNode)); //v7 -> v8 权值为5  
	e->next = G->Vertex[7].FirstEdge;
	e->AdjVex = 8;
	e->weight = 5;
	G->Vertex[7].FirstEdge = e;
	++G->Vertex[e->AdjVex].in;

	e = (EdgeNode*)malloc(sizeof(EdgeNode)); //v8 -> v9 权值为3  
	e->next = G->Vertex[8].FirstEdge;
	e->AdjVex = 9;
	e->weight = 3;
	G->Vertex[8].FirstEdge = e;
	++G->Vertex[e->AdjVex].in;
}
void TopoLogicalSort(Graph *G)
{
	int *Stack;   //用于存储入度为0的顶点下标 
	int top = 0;  // Stack栈的指针  
	int count = 0; //统计输出的顶点数  
	int gettop; //去除的顶点下标  
	Stack = (int *)malloc(sizeof(int) * G->NumVertex);
	top2 = 0;
	Stack2 = (int *)malloc(sizeof(int) * G->NumVertex); //存储拓扑排序的序列  
	for (int i = 0; i < G->NumVertex; ++i)
	{
		if (!(G->Vertex[i].in)) //将入度为0的顶点存储在Stack栈中  
		{
			Stack[++top] = i;
		}			
	}
	etv = (int*)malloc(sizeof(int) * G->NumVertex);
	for (int i = 0; i < G->NumVertex; ++i) //事件最早发生时间初始化为0  
	{
		etv[i] = 0;
	}
	while (top != 0) //Stack栈不为空,即还有未处理完的顶点  
	{
		gettop = Stack[top--]; //出栈  
		count++;
		Stack2[++top2] = gettop; //将已处理的顶点压入Stack2栈中  
		//      printf("V%d ",G->Vertex[gettop].data);  
		for (EdgeNode *e = G->Vertex[gettop].FirstEdge; e; e = e->next) //处理下标为gettop的顶点所连接的顶点  
		{
			int k = e->AdjVex;
			if (!(--G->Vertex[k].in)) //如果被指向的顶点入度减1为0的话压入Stack栈中  
			{
				Stack[++top] = k;
			}				
			if (etv[gettop] + e->weight > etv[k]) //事件最早发生的时间  
			{
				etv[k] = etv[gettop] + e->weight;
			}				
		}
	}
	////打印排序结果,倒序
	//while (top2)
	//{
	//	printf("%d:%d:\n", Stack2[top2], etv[top2]);
	//	top2--;
	//}
	//  printf("\n");  
	if (count < G->NumVertex) //如果顶点没有完全输出  
	{
		printf("拓扑排序错误,程序即将退出:\n");
		system("pause");
		exit(1);
	}
}
void CriticalPath(Graph *G)
{
	int ete, lte; //声明事件最早发生时间和最迟发生时间的变量  
	TopoLogicalSort(G); //拓扑排序求事件的最早发生时间和拓扑序列Stack2  
	ltv = (int *)malloc(sizeof(EdgeNode) * G->NumVertex);

	//初始化事件最晚发生时间  都初始化为最大值(汇点时间)
	for (int i = 0; i < G->NumVertex; ++i) 
	{
		ltv[i] = etv[G->NumVertex - 1];
	}
	//计算ltv的值 从栈顶的最大ltv的汇点时间值依次往前递减直到栈空
	//从汇点倒过来逐个计算ltv
	while (top2 != 0) //如果Stack2栈不为空  
	{
		int gettop = Stack2[top2--]; //出栈  
		for (EdgeNode *e = G->Vertex[gettop].FirstEdge; e; e = e->next) //处理下标为gettop的顶点所连接的顶点  
		{
			int k = e->AdjVex;
			if (ltv[k] - e->weight < ltv[gettop])
			{
				ltv[gettop] = ltv[k] - e->weight;
			}				
		}
	}
	//通过etv和ltv计算ete和lte
	for (int i = 0; i < G->NumVertex; ++i)
	{
		for (EdgeNode *e = G->Vertex[i].FirstEdge; e; e = e->next)
		{
			//k为当前选定的订单i的下一个顶点 ete就是i点的最早发生时间, lte为下一顶点k的ltv(最晚发生时间)-e的权值(i-k的权值),两者如果相等就在关键路径上
			int k = e->AdjVex;
			ete = etv[i];  //事件最早发生时间  
			lte = ltv[k] - e->weight; //事件最晚发生时间  
			if (ete == lte) //相等即在关键路径上  
			{
				printf(" <V%d -> V%d) weight: %d\n", G->Vertex[i].data, G->Vertex[k].data, e->weight);
			}
		}
	}
}
int main()
{
	Graph G;
	CreateGraph(&G);
	//TopoLogicalSort(&G);
	CriticalPath(&G);
	system("pause");
	return 0;
}
#endif