#pragma once
#pragma warning(disable:4996)

/* 图的邻接矩阵表示法 */

#define n 6
#define e 8

typedef struct graph
{
	char vexs[n];
	int arcs[n][n];
}graph;

typedef struct node
{
	int adjvex;
	struct node *next;
}edgenode;

typedef struct vexnode
{
	char vex;
	edgenode *link;
}vexnode;

typedef struct
{
	int data[n];
	int rear, front;
}queue;
