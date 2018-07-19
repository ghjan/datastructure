#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "time.h"
#include "basesort.h"
#pragma warning(disable:4996)


void readPATData(NodeWithkeys* nodes, int *N, int *K, int *M)
{
	scanf("%d %d %d", N, K, M);

	int data;
	int *fullMarks = new int[*K];
	for (int i = 0; i < *K && scanf("%d", &data) != EOF; i++) {
		fullMarks[i] = data;
	}

	nodes = (NodeWithkeys *)malloc(*M * sizeof(struct NodeWithkeys)); //new NodeWithkeys[*M];
	int userid, problemId, score;
	for (int j = 0; j < *M && scanf("%d %d %d", &userid, &problemId, &score) != EOF; j++) {
		nodes[j].keys=(int *)malloc(3 * sizeof(int));
		nodes[j].keys[0] = userid;
		nodes[j].keys[1] = problemId;
		nodes[j].keys[2] = score;

	}

}

int SolvePatJudge() {
	/*--------------- 对结构体Node中的键值key1,key2排序 ---------------*/
	int N, K, M;
	NodeWithkeys *nodesA = NULL;
	readPATData(nodesA, &N, &K, &M);

	/* 调用接口 */
	qsort(nodesA, M, sizeof(struct NodeWithkeys), Compare3Keys);
	PrintNode(nodesA, M, 3);

	free(nodesA);

	return 0;
}