#include "stdafx.h"
#include <stdio.h>  
#include <stdlib.h>  
#include "floyd.h"

void createGraph(gLink g)
{
	int n, v, data;
	printf("�����붥���������");
	scanf("%d %d", &n, &v);
	g->n = n;
	g->v = v;
	int i;
	for (i = 0; i<n; i++)
	{
		printf("�����붥��%dȨֵ", i);
		scanf("%d", &data);
		g->adj[i].data = data;
		g->adj[i].first = NULL;
	}
	printf("���������Ϣ");
	int v1, v2, da;
	for (i = 0; i<v; i++)
	{
		scanf("%d %d %d", &v1, &v2, &da);
		sLink s = (sLink)malloc(sizeof(Side));
		s->toVertex = v2;
		s->next = g->adj[v1].first;
		g->adj[v1].first = s;
		s->data = da;
	}
}

int dis[15][15];
void floyd(gLink g)
{
	int i, j, k;
	//��ʼ��
	for (i = 0; i<g->n; i++)
	{
		for (j = 0; j<g->n; j++)
		{
			dis[i][j] = 1000;
		}
		dis[i][i] = 0;
	}
	for (i = 0; i<g->n; i++)
	{
		sLink s = g->adj[i].first;
		while (s)
		{
			dis[i][s->toVertex] = s->data;
			s = s->next;
		}
	}
	//�㷨
	for (k = 0; k<g->n; k++)//�ѵ�K������ӵ��м�㼯����
	{
		for (i = 0; i<g->n; i++)//����
		{
			for (j = 0; j<g->n; j++)//����
			{
				if (dis[i][k] + dis[k][j]<dis[i][j])//i-->k-->j
				{
					dis[i][j] = dis[i][k] + dis[k][j];
				}
			}
		}
	}
	//���
	for (i = 0; i<g->n; i++)
	{
		for (j = 0; j<g->n; j++)
		{
			printf("%-5d", dis[i][j]);
		}
		printf("\n");
	}
}

int SolveFloyd()
{
	gLink g = (gLink)malloc(sizeof(Graph));
	createGraph(g);
	floyd(g);
	return 0;
}
