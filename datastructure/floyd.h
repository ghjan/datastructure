#pragma once 
#pragma warning(disable:4996)

typedef struct Side//边
{
	int toVertex;//边指向的点
	int data;
	struct Side *next;
}Side, *sLink;
typedef struct Vertex//顶点
{
	int data;
	sLink first;//第一个边
}Vertex, AdjList[20];
typedef struct Graph//图
{
	AdjList adj;//顶点数组，注意不是指针，用.不用->
	int n, v;//顶点数，边数
}Graph, *gLink;

void createGraph(gLink g);
void floyd(gLink g);