#pragma once
#pragma warning(disable:4996)

#define MAX_VALUE 10  

typedef struct EdgeNode {//边顶点  
	int index;//该顶点下标  
	struct EdgeNode *next;//存储下一个边顶点  
}EdgeNode;
typedef struct HeadNode {//表顶点  
	char data;
	EdgeNode *edgeNode;
}HeadNode, AdjacencyList[MAX_VALUE];

typedef struct Graph {//图  
	AdjacencyList list;
	int vexNum;//当前顶点数  
	int edgeNum;//当前边数  
}Graph;

//找到该元素所在的下标  
int locate(Graph *graph, char ch);
//输出矩阵
void outputGraph(Graph *graph);

//广度优先搜索 
void BFSGraph(Graph *graph);

//深度搜索  
void DFS(Graph *graph, int index, int *visited);
//深度优先搜索  
void DFSGraph(Graph *graph);

void work(char ch);