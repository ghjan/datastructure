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
	bool isFirst = true;
	char userid[5];
	int problemId, score;
	for (int j = 0; j < *M * 3; j++) {
		int index = j % 3;
		switch (index) {
		case 0:
			if (scanf("%s", &userid) != EOF) {
				data = atoi(userid);
			}
			else {
				return;
			}
			nodes[j / 3].keys = (int *)malloc(3 * sizeof(int));
			break;
		case 1:
		case 2:
			if (scanf("%d", &data) == EOF) {
				return;
			}
			break;
		}

		nodes[j / 3].keys[index] = data;

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

	delete[]nodesA;

	return 0;
}