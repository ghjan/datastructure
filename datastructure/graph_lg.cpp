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

	//ע��:����Ĭ�϶����Ŵ�0��ʼ����(Graph->Nv-1)
	for (V = 0; V < Graph->Nv; V++)
	{
		for (W = 0; W < Graph->Nv; W++)
			Graph->G[V].FirstEdge = NULL;
	}
	return Graph;

}

//����һ���ߣ�������ͷ��
void InsertEdge(LGraph Graph, Edge E)
{
	PtrToAdjVNode NewNode;
	//����� <V1, V2>
	//ΪV2�����µ��ڽӵ�
	NewNode = (PtrToAdjVNode)malloc(sizeof(AdjVNode));
	NewNode->AdjV = E->V2;
	NewNode->Weight = E->Weight;
	NewNode->Next = Graph->G[E->V1].FirstEdge;
	Graph->G[E->V1].FirstEdge = NewNode;

	//��������ͼ,��Ҫ����� <V2, V1>
	//ΪV1�����µ��ڽӵ�
	PtrToAdjVNode NewNode2 = (PtrToAdjVNode)malloc(sizeof(AdjVNode));
	NewNode2->AdjV = E->V1;
	NewNode2->Weight = E->Weight;
	Graph->G[E->V2].FirstEdge = NewNode2;

}