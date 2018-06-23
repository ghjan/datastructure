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
	for (V = 0; V < Graph->Nv; V++)
	{
		for (W = 0; W < Graph->Nv; W++)
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
	Graph->G[E->V1][E->V2] = E->Weight;

	//若是无向图,还要插入边 <V2, V1>
	Graph->G[E->V2][E->V1] = E->Weight;

}