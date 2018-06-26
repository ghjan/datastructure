#pragma once
#pragma warning(disable:4996)
#define WeightType float
#define DataType int
typedef int Vertex; //�ö����±��ʾ���㣬Ϊ����

#define MaxVertexNum 100

//AdjVNode:������
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode {
	Vertex AdjV; // �ڽӵ��±�
	WeightType Weight; // ��Ȩ��
	PtrToAdjVNode Next;
};

//Vnode:������						   
typedef struct Vnode {  
	PtrToAdjVNode FirstEdge;  //����ָ������ĵ�һ����
	DataType Data; // �涥�������
} AdjList[MaxVertexNum];  // AdjList:�ڽӱ�-��������

typedef struct GNode *PtrToGNode;
struct GNode {
	int Nv; // ������
	int Ne; // ����
	AdjList G; // �ڽӱ�-��������
};
typedef PtrToGNode LGraph; // ���ڽӱ�ʽ�洢��ͼ����

typedef struct ENode *PtrToENode; //
struct ENode {
	Vertex V1, V2;		//����� <V1, V2>
	WeightType Weight;	//Ȩ��
};
typedef PtrToENode Edge;

//��ʼ��
LGraph CreateGraph(int VertexNum);
//����һ���ߣ�������ͷ��
void InsertEdge(LGraph Graph, Edge E);

//�����ؽ���һ��LGraph
LGraph BuildGraph();
