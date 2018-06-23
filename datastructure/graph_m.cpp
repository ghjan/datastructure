#include "stdafx.h"
#include <stdio.h>  
#include <stdlib.h>  
#include "graph_m.h"

MGraph CreateGraph(int VertexNum)
{
	Vertex V, W;
	MGraph Graph;

	Graph = (MGraph)malloc(sizeof(GNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;

	//ע��:����Ĭ�϶����Ŵ�0��ʼ����(Graph->Nv-1)
	for (V = 0; V < Graph->Nv; V++)
	{
		for (W = 0; W < Graph->Nv; W++)
			Graph->G[V][W] = 0; //����INFINITY
	}
	return Graph;

}

void InsertEdge(MGraph Graph, Edge E)
{
	//����� <V1, V2>
	Graph->G[E->V1][E->V2] = E->Weigth;

	//��������ͼ,��Ҫ����� <V2, V1>
	Graph->G[E->V2][E->V1] = E->Weigth;

}

//�����ؽ���һ��MGraph
/*
�����ʽ
 Nv Ne
 V1 V2 Weight

*/

MGraph BuildGraph()
{
	MGraph Graph;
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
			scanf("%d %d %d", &E->V1, &E->V2, &E->Weigth); //����ÿ���ߵ�����
			InsertEdge(Graph, E);
		}
	}

	//������������ݵĻ�����������
	printf("����ÿһ����������(%d��)\n", Graph->Nv);
	for (V = 0; V < Graph->Nv; V++)
	{
		scanf(" %c", &(Graph->Data[V])); //����ÿһ����������
	}
	return Graph;
}

