#pragma once 
#pragma warning(disable:4996)

typedef struct Side//��
{
	int toVertex;//��ָ��ĵ�
	int data;
	struct Side *next;
}Side, *sLink;
typedef struct Vertex//����
{
	int data;
	sLink first;//��һ����
}Vertex, AdjList[20];
typedef struct Graph//ͼ
{
	AdjList adj;//�������飬ע�ⲻ��ָ�룬��.����->
	int n, v;//������������
}Graph, *gLink;

void createGraph(gLink g);
void floyd(gLink g);