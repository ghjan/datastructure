#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "time.h"
#include "basesort.h"
#pragma warning(disable:4996)


NodeWithkeys* readPATData(int *N, int *K, int *M)
{
	scanf("%d %d %d", N, K, M);

	int data;
	int *fullMarks = new int[*K];
	for (int i = 0; i < *K && scanf(" %d", &data) != EOF; i++) {
		fullMarks[i] = data;
	}

	NodeWithkeys *nodes = new NodeWithkeys[*M];
	bool isFirst = true;
	char userid[]="";
	int userid, problemId, score;
	for (int j = 0; j < *M && scanf("%s %d %d", userid, &problemId, &score) != EOF; j++) {
		int jj = 0;
		for (jj = 0; userid[jj] == '0'; jj++);
		nodes[j].keys[0] = atoi(userid + jj);
		nodes[j].keys[1] = problemId;
		nodes[j].keys[2] = score;
	}

	return nodes;
}

int SolvePatJudge() {
	/*--------------- 对结构体Node中的键值key1,key2排序 ---------------*/
	int N, K, M;
	NodeWithkeys *nodesA = readPATData(&N, &K, &M);

	/* 调用接口 */
	qsort(nodesA, M, sizeof(struct NodeWithkeys), Compare3Keys);
	PrintNode(nodesA, M, 3);

	delete[]nodesA;

	return 0;
}