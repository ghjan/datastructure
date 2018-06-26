#include "stdafx.h"
#include <stdio.h>  
#include <stdlib.h>  
#include "graph_m.h"

//��ʼ��
MGraph CreateMGraph(int VertexNum)
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

//����һ����
void InsertEdge_M(MGraph Graph, Edge E)
{
	//����� <V1, V2>
	Graph->G[E->V1][E->V2] = E->Weight;

	//��������ͼ,��Ҫ����� <V2, V1>
	Graph->G[E->V2][E->V1] = E->Weight;

}

//�����ؽ���һ��MGraph
/*
�����ʽ
 Nv Ne
 V1 V2 Weight

*/
MGraph BuildGraph_M()
{
	MGraph Graph;
	Edge E;
	int Nv;
	Vertex V;
	printf("���붥����:\n");
	scanf("%d", &Nv); //���붥����
	Graph = CreateMGraph(Nv);
	printf("�������:\n");
	scanf("%d", &(Graph->Ne)); //�������
	if (Graph->Ne != 0)
	{
		E = (Edge)malloc(sizeof(ENode));
		printf("����ÿ���ߵ�����:\n");
		for (int i = 0; i < Graph->Ne; i++)
		{
			scanf("%d %d %f", &E->V1, &E->V2, &E->Weight); //����ÿ���ߵ�����
			InsertEdge_M(Graph, E);
		}
	}

	//������������ݵĻ�����������
	printf("����ÿһ����������(%d��)\n", Graph->Nv);
	for (V = 0; V < Graph->Nv; V++)
	{
		scanf(" %d", &(Graph->Data[V])); //����ÿһ����������
	}
	return Graph;
}

