#pragma once
#pragma warning(disable:4996)

#define MAX_VALUE 10  

typedef struct EdgeNode {//�߶���  
	int index;//�ö����±�  
	struct EdgeNode *next;//�洢��һ���߶���  
}EdgeNode;
typedef struct HeadNode {//����  
	char data;
	EdgeNode *edgeNode;
}HeadNode, AdjacencyList[MAX_VALUE];

typedef struct Graph {//ͼ  
	AdjacencyList list;
	int vexNum;//��ǰ������  
	int edgeNum;//��ǰ����  
}Graph;

//�ҵ���Ԫ�����ڵ��±�  
int locate(Graph *graph, char ch);
//�������
void outputGraph(Graph *graph);

//����������� 
void BFSGraph(Graph *graph);

//�������  
void DFS(Graph *graph, int index, int *visited);
//�����������  
void DFSGraph(Graph *graph);

void work(char ch);