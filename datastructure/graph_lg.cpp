#include "stdafx.h"
#include <stdio.h>  
#include <stdlib.h>  
#include "graph_lg.h"

LGraph CreateGraph(int VertexNum)
{
	Vertex V, W;
	LGraph Graph;

	Graph = (LGraph)malloc(sizeof(GNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;

	//注意:这里默认顶点编号从0开始，到(Graph->Nv-1)
	for (V = 0; V < MaxVertexNum; V++)
	{
		Graph->G[V].FirstEdge = NULL;
	}
	return Graph;

}

//插入一条边，插入在头部
void InsertEdge(LGraph Graph, Edge E)
{
	PtrToAdjVNode NewNode;
	//插入边 <V1, V2>
	//为V2建立新的邻接点
	NewNode = (PtrToAdjVNode)malloc(sizeof(AdjVNode));
	NewNode->AdjV = E->V2;
	NewNode->Weight = E->Weight;
	//v2插入v1的表头
	NewNode->Next = Graph->G[E->V1].FirstEdge;
	Graph->G[E->V1].FirstEdge = NewNode;

	//若是无向图,还要插入边 <V2, V1>
	//为V1建立新的邻接点
	NewNode = (PtrToAdjVNode)malloc(sizeof(AdjVNode));
	NewNode->AdjV = E->V1;
	NewNode->Weight = E->Weight;
	//V1插入V2的表头
	NewNode->Next = Graph->G[E->V2].FirstEdge;
	Graph->G[E->V2].FirstEdge = NewNode;
}


//完整地建立一个LGraph
/*
输入格式
Nv Ne
V1 V2 Weight

*/
LGraph BuildGraph()
{
	LGraph Graph;
	Edge E;
	int Nv;
	Vertex V;
	printf("输入顶点数:\n");
	scanf("%d", &Nv); //输入顶点数
	Graph = CreateGraph(Nv);
	printf("输入边数:\n");
	scanf("%d", &(Graph->Ne)); //输入边数
	if (Graph->Ne != 0)
	{
		E = (Edge)malloc(sizeof(ENode));
		printf("输入每个边的数据:\n");
		for (int i = 0; i < Graph->Ne; i++)
		{
			scanf("%d %d %f", &E->V1, &E->V2, &E->Weight); //输入每个边的数据
			InsertEdge(Graph, E);
		}
	}

	//如果顶点有数据的话，读入数据
	printf("输入每一个顶点数据(%d个)\n", Graph->Nv);
	for (V = 0; V < Graph->Nv; V++)
	{
		if (Graph->G[V + 1].FirstEdge) {
			scanf(" %c", &(Graph->G[V].Data)); //输入每一个顶点数据
			V++;
		}
	}
	return Graph;
}

