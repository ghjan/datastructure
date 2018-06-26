#pragma once
typedef struct GNode *PtrToGNODE;
#define WeightType float
#define DataType int
#define MaxVertexNum 100
struct GNode {
	int Nv; //顶点数
	int Ne; //边数
	WeightType G[MaxVertexNum][MaxVertexNum]; //邻接矩阵保存每一条边的权重
	DataType Data[MaxVertexNum]; //顶点数据
};
typedef PtrToGNODE MGraph; //以邻接矩阵存储的图类型

typedef int Vertex; //用顶点下标表示顶点，为整型
typedef struct ENode *PtrToENode; //
struct ENode {
	Vertex V1, V2;		//有向边 <V1, V2>
	WeightType Weight;	//权重
};
typedef PtrToENode Edge;
