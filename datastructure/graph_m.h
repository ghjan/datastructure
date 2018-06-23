#pragma once
typedef struct GNode *PtrToGNODE;
#define WeightType float
#define DataType int
#define MaxVertexNum 100
struct GNode {
	int Nv; //������
	int Ne; //����
	WeightType G[MaxVertexNum][MaxVertexNum]; //�ڽӾ��󱣴�ÿһ���ߵ�Ȩ��
	DataType Data[MaxVertexNum]; //��������
};
typedef PtrToGNODE MGraph; //���ڽӾ���洢��ͼ����

typedef int Vertex; //�ö����±��ʾ���㣬Ϊ����
typedef struct ENode *PtrToENode; //
struct ENode {
	Vertex V1, V2;		//����� <V1, V2>
	WeightType Weigth;	//Ȩ��
};
typedef PtrToENode Edge;
