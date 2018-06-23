#pragma once

#define WeightType float
#define DataType int
typedef int Vertex; //�ö����±��ʾ���㣬Ϊ����

#define MaxVertexNum 100

typedef struct GNode *PtrToGNode;
struct GNode {
	int Nv; // ������
	int Ne; // ����
	AdjList G; // �ڽӱ�-��������
};
typedef PtrToGNode LGraph; // ���ڽӱ�ʽ�洢��ͼ����

//Vnode:������						   
typedef struct Vnode {  
	PtrToAdjVNode FirstEdge;  //����ָ������ĵ�һ����
	DataType Data; // �涥�������
} AdjList[MaxVertexNum];  // AdjList:�ڽӱ�-��������

//AdjVNode:������
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode {
	Vertex AdjV; // �ڽӵ��±�
	WeightType Weight; // ��Ȩ��
	PtrToAdjVNode Next;
};

typedef struct ENode *PtrToENode; //
struct ENode {
	Vertex V1, V2;		//����� <V1, V2>
	WeightType Weight;	//Ȩ��
};
typedef PtrToENode Edge;
