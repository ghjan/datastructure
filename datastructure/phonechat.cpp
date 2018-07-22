#include "stdafx.h"
#include <math.h>
#include <stdlib.h>
#include "hashtable.h"
using namespace std;
#pragma warning(disable:4996)


HashTable ReadPhoneCallRecord()
{
	//N个记录
	int N;
	scanf("%d", &N);
	int tableSize = NextPrime(N * 2);
	HashTable table = CreateTable(tableSize);
	for (int j = 0; j < N; j++) {
		ElementType key = (ElementType)malloc(11 * sizeof(char));
		scanf("%s", key);
		Insert(table, key);
		key = (ElementType)malloc(11 * sizeof(char));
		scanf("%s", key);
		Insert(table, key);
	}
	return table;
}

void ScanAndOutput(HashTable table) {

	int maxCallCount = 0;
	char *mobileCrazy = NULL;
	int championCount = 0;
	for (int i = 0; i < table->TableSize; i++) {
		if (table->Cells[i].Info == Legitimate) {
			if (table->Cells[i].Count > maxCallCount) {
				championCount = 1;
				maxCallCount = table->Cells[i].Count;
				mobileCrazy = table->Cells[i].Data;
			}
			else if (table->Cells[i].Count == maxCallCount) { //并列冠军
				if (atoi(table->Cells[i].Data) < atoi(mobileCrazy)) { //取更小的
					mobileCrazy = table->Cells[i].Data;
				}
				championCount++;
			}
		}
	}
	if (mobileCrazy != NULL) {
		printf("%s %d", mobileCrazy, maxCallCount);
	}
}


int SolvePhoneChat() {
	HashTable table = ReadPhoneCallRecord();
	ScanAndOutput(table);
	DestroyHashTable(table);
	return 0;
}