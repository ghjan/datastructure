#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

#include "time.h"
#include "basesort.h"
#pragma warning(disable:4996)
using namespace std;

#define MaxNForNode 10000

<<<<<<< HEAD
void readPATData(NodeWithkeys* nodes, int *N, int *K, int *M)
=======
NodeWithkeys* readPATData(int *mapNode, int *N, int *K, int *M)
>>>>>>> c84aa7cf2aab8cd89095217814eecb177534614a
{
	//N个user，K个problem，M个记录
	scanf("%d %d %d", N, K, M);

	int data;
	int *fullMarks = new int[*K];
<<<<<<< HEAD
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

=======
	for (int i = 0; i < *K && scanf(" %d", &data); i++) {
		fullMarks[i] = data;
	}

	NodeWithkeys *nodes = (NodeWithkeys *)malloc(*N * sizeof(struct NodeWithkeys));
	for (int i = 0; i < *N; i++) {
		nodes[i].keys = (int *)malloc(3 * sizeof(int));
		nodes[i].values = (int *)malloc(*K * sizeof(int));
		for (int j = 0; j < 3; j++) {
			nodes[i].keys[j] = 0;
		}

		for (int j = 0; j < *K; j++) {
			nodes[i].values[j] = 0;
		}
	}
	int userid, problemId, score;
	int nodeidNext = 0;
	int nodeid = -1;
	for (int j = 0; j < *M && scanf("%d %d %d", &userid, &problemId, &score) != EOF; j++) {
		nodeid = mapNode[userid];
		if (nodeid < 0) {
			nodeid = mapNode[userid] = nodeidNext++;
		}

		if (score > nodes[nodeid].values[problemId - 1]) { //同一个problem，多次提交，取最高分；但是多次提交一样的分数，只算一次
			nodes[nodeid].values[problemId - 1] = score;
			if (fullMarks[problemId - 1] == score) { //可以防止这种情况：多次提交最高分，算多次perfect
				nodes[nodeid].keys[1] ++;  //perfect_count:答题perfect的次数
			}
		}
		nodes[nodeid].keys[2] = userid; // userid

	}

	//sum total score
	for (int j = 0; j < *N; j++) {
		for (int jj = 0; jj < *K; jj++) {
			nodes[j].keys[0] += nodes[j].values[jj]; //total score
		}
	}
	return nodes;
>>>>>>> c84aa7cf2aab8cd89095217814eecb177534614a
}

int length(char*s) {
	int i;
	for (i = 0; s[i] != '\0'; i++); // 注意 不等号
	return i;
}

char* convertToAddress(int add) {

	char *strCat = (char *)malloc(5 * sizeof(char));
	sprintf(strCat, "%05d", (unsigned int)add);
	return strCat;
}

void PrintPatJudge(NodeWithkeys *data, int N, int K)
{
	int i;
	int rank = 0;
	int scorePrev = 99999999;
	char * address = NULL;
	for (i = 0; i < N; i++) {
		if (data[i].keys[0] <= 0)continue;
		int score = data[i].keys[0];
		if (scorePrev > score) {
			scorePrev = score;
			rank++;
		}
		printf("%d ", rank);
		address = convertToAddress(data[i].keys[2]);
		printf("%s ", address); //convertToAddress(data[i].keys[2])  printf(" %d ", data[i].keys[2])
		printf("%d ", data[i].keys[0]);
		for (int j = 0; j < K; j++) {
			if (data[i].values[j] > 0) {
				printf("%d ", data[i].values[j]);
			}
			else {
				printf("- ");
			}
		}
		printf("\n");
	}
	if (NULL != address)
		free(address);

}

int SolvePatJudge() {
	/*--------------- 对结构体Node中的键值key1,key2排序 ---------------*/
<<<<<<< HEAD
	int N, K, M;
	NodeWithkeys *nodesA = NULL;
	readPATData(nodesA, &N, &K, &M);

	/* 调用接口 */
	qsort(nodesA, M, sizeof(struct NodeWithkeys), Compare3Keys);
	PrintNode(nodesA, M, 3);

	free(nodesA);
=======
	int N, K, M; //user数量，problem数量，M条记录
	int *mapNode = (int *)malloc(MaxNForNode * sizeof(int));
	for (int i = 0; i < MaxNForNode; i++) {
		mapNode[i] = -1;
	}
	NodeWithkeys *nodesA = readPATData(mapNode, &N, &K, &M);

	/* 调用接口 */
	qsort(nodesA, N, sizeof(struct NodeWithkeys), Compare3Keys);
	PrintPatJudge(nodesA, N, K);
>>>>>>> c84aa7cf2aab8cd89095217814eecb177534614a

	for (int i = 0; i < N; i++) {
		if (NULL != nodesA->keys)
			free(nodesA->keys);
		if (NULL != nodesA->values)
			free(nodesA->values);
	}
	free(nodesA);
	free(mapNode);
	return 0;
}