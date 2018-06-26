#pragma once
#pragma warning(disable:4996)
#define WeightType float
#define DataType int
#define MaxVertexNum 100
struct GNode {
	int Nv; //������
	int Ne; //����
	WeightType G[MaxVertexNum][MaxVertexNum]; //�ڽӾ��󱣴�ÿһ���ߵ�Ȩ��
	DataType Data[MaxVertexNum]; //��������
};
typedef struct GNode *PtrToGNODE;

typedef PtrToGNODE MGraph; //���ڽӾ���洢��ͼ����

typedef int Vertex; //�ö����±��ʾ���㣬Ϊ����
typedef struct ENode *PtrToENode; //
struct ENode {
	Vertex V1, V2;		//����� <V1, V2>
	WeightType Weight;	//Ȩ��
};
typedef PtrToENode Edge;

//��ʼ��
MGraph CreateMGraph(int VertexNum);

//����һ����
void InsertEdge_M(MGraph Graph, Edge E);

//�����ؽ���һ��MGraph
MGraph BuildGraph_M();