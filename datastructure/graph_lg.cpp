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
	for (V = 0; V < MaxVertexNum; V++)
	{
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
	//v2����v1�ı�ͷ
	NewNode->Next = Graph->G[E->V1].FirstEdge;
	Graph->G[E->V1].FirstEdge = NewNode;

	//��������ͼ,��Ҫ����� <V2, V1>
	//ΪV1�����µ��ڽӵ�
	NewNode = (PtrToAdjVNode)malloc(sizeof(AdjVNode));
	NewNode->AdjV = E->V1;
	NewNode->Weight = E->Weight;
	//V1����V2�ı�ͷ
	NewNode->Next = Graph->G[E->V2].FirstEdge;
	Graph->G[E->V2].FirstEdge = NewNode;
}


//�����ؽ���һ��LGraph
/*
�����ʽ
Nv Ne
V1 V2 Weight

*/
LGraph BuildGraph()
{
	LGraph Graph;
	Edge E;
	int Nv;
	Vertex V;
	printf("���붥����:\n");
	scanf("%d", &Nv); //���붥����
	Graph = CreateGraph(Nv);
	printf("�������:\n");
	scanf("%d", &(Graph->Ne)); //�������
	if (Graph->Ne != 0)
	{
		E = (Edge)malloc(sizeof(ENode));
		printf("����ÿ���ߵ�����:\n");
		for (int i = 0; i < Graph->Ne; i++)
		{
			scanf("%d %d %f", &E->V1, &E->V2, &E->Weight); //����ÿ���ߵ�����
			InsertEdge(Graph, E);
		}
	}

	//������������ݵĻ�����������
	printf("����ÿһ����������(%d��)\n", Graph->Nv);
	for (V = 0; V < Graph->Nv; V++)
	{
		if (Graph->G[V + 1].FirstEdge) {
			scanf(" %c", &(Graph->G[V].Data)); //����ÿһ����������
			V++;
		}
	}
	return Graph;
}

