#include "stdafx.h"
#include <stdio.h>  
#include <stdlib.h>  
#include "graph_m.h"

//初始化
MGraph CreateMGraph(int VertexNum)
{
	Vertex V, W;
	MGraph Graph;

	Graph = (MGraph)malloc(sizeof(GNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;

	//注意:这里默认顶点编号从0开始，到(Graph->Nv-1)
	for (V = 0; V < Graph->Nv; V++)
	{
		for (W = 0; W < Graph->Nv; W++)
			Graph->G[V][W] = 0; //或者INFINITY
	}
	return Graph;

}

//插入一条边
void InsertEdge_M(MGraph Graph, Edge E)
{
	//插入边 <V1, V2>
	Graph->G[E->V1][E->V2] = E->Weight;

	//若是无向图,还要插入边 <V2, V1>
	Graph->G[E->V2][E->V1] = E->Weight;

}

//完整地建立一个MGraph
/*
输入格式
 Nv Ne
 V1 V2 Weight

*/
MGraph BuildGraph_M()
{
	MGraph Graph;
	Edge E;
	int Nv;
	Vertex V;
	printf("输入顶点数:\n");
	scanf("%d", &Nv); //输入顶点数
	Graph = CreateMGraph(Nv);
	printf("输入边数:\n");
	scanf("%d", &(Graph->Ne)); //输入边数
	if (Graph->Ne != 0)
	{
		E = (Edge)malloc(sizeof(ENode));
		printf("输入每个边的数据:\n");
		for (int i = 0; i < Graph->Ne; i++)
		{
			scanf("%d %d %f", &E->V1, &E->V2, &E->Weight); //输入每个边的数据
			InsertEdge_M(Graph, E);
		}
	}

	//如果顶点有数据的话，读入数据
	printf("输入每一个顶点数据(%d个)\n", Graph->Nv);
	for (V = 0; V < Graph->Nv; V++)
	{
		scanf(" %d", &(Graph->Data[V])); //输入每一个顶点数据
	}
	return Graph;
}

