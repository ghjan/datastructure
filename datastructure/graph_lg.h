#pragma once

#define WeightType float
#define DataType int
typedef int Vertex; //用顶点下标表示顶点，为整型

#define MaxVertexNum 100

typedef struct GNode *PtrToGNode;
struct GNode {
	int Nv; // 顶点数
	int Ne; // 边数
	AdjList G; // 邻接表-顶点数组
};
typedef PtrToGNode LGraph; // 以邻接表方式存储的图类型

//Vnode:顶点结点						   
typedef struct Vnode {  
	PtrToAdjVNode FirstEdge;  //总是指向链表的第一条边
	DataType Data; // 存顶点的数据
} AdjList[MaxVertexNum];  // AdjList:邻接表-顶点数组

//AdjVNode:边类型
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode {
	Vertex AdjV; // 邻接点下标
	WeightType Weight; // 边权重
	PtrToAdjVNode Next;
};

typedef struct ENode *PtrToENode; //
struct ENode {
	Vertex V1, V2;		//有向边 <V1, V2>
	WeightType Weight;	//权重
};
typedef PtrToENode Edge;
