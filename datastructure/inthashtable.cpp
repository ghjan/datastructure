#include "stdafx.h"
#include <math.h>
#include <stdlib.h>
#include "inthashtable.h"
using namespace std;
#pragma warning(disable:4996)


Position Hash(ElementType Key, int tableSize) {
	return Key % tableSize;
}

Position Find(IntHashTable H, ElementType Key)
{
	Position CurrentPos, NewPos;
	int CNum = 0; /* 记录冲突次数 */
	NewPos = CurrentPos = Hash(Key, H->TableSize); /* 初始散列位置 */
												   /* 当该位置的单元非空，并且不是要找的元素时，发生冲突 */
	while (H->Cells[NewPos].Info != Empty && H->Cells[NewPos].Data != Key && CNum < H->TableSize) {
		/* 字符串类型的关键词需要 strcmp 函数!! */
		/* 统计1次冲突，并判断奇偶次 */
		if (++CNum % 2) { /* 奇数次冲突 */
			NewPos = CurrentPos + (CNum + 1)*(CNum + 1) / 4; /* 增量为+[(CNum+1)/2]^2 */
			if (NewPos >= H->TableSize)
				NewPos = NewPos % H->TableSize; /* 调整为合法地址 */
		}
		else { /* 偶数次冲突 */
			NewPos = CurrentPos - CNum * CNum / 4; /* 增量为-(CNum/2)^2 */
			while (NewPos < 0)
				NewPos += H->TableSize; /* 调整为合法地址 */
		}
	}
	if (CNum >= H->TableSize) {
		return -1;
	}
	return NewPos; /* 此时NewPos或者是Key的位置，或者是一个空单元的位置（表示找不到）*/
}

Position FindLinear(IntHashTable H, ElementType Key)
{
	Position CurrentPos, NewPos;
	int CNum = 0; /* 记录冲突次数 */
	NewPos = CurrentPos = Hash(Key, H->TableSize); /* 初始散列位置 */
												   /* 当该位置的单元非空，并且不是要找的元素时，发生冲突 */
	while (H->Cells[NewPos].Info != Empty && H->Cells[NewPos].Data != Key && CNum < H->TableSize) {
		NewPos = (CurrentPos + CNum + 1) % H->TableSize;
	}
	if (CNum >= H->TableSize) {
		return -1;
	}
	return NewPos; /* 此时NewPos或者是Key的位置，或者是一个空单元的位置（表示找不到）*/
}
Position Insert(IntHashTable H, ElementType Key)
{
	Position Pos = Find(H, Key); /* 先检查Key是否已经存在 */
	if (H->Cells[Pos].Info != Legitimate) { /* 如果这个单元没有被占，说明Key可以插入在此 */
		H->Cells[Pos].Info = Legitimate;
		H->Cells[Pos].Data = Key;
		/*字符串类型的关键词需要 strcpy 函数!! */
		return Pos;
	}
	else {
		printf("键值已存在");
		return Pos;
	}
}

Position InsertLinear(IntHashTable H, ElementType Key)
{
	Position Pos = FindLinear(H, Key); /* 先检查Key是否已经存在 */
	if (Pos < 0)
		return Pos;
	if (H->Cells[Pos].Info != Legitimate) { /* 如果这个单元没有被占，说明Key可以插入在此 */
		H->Cells[Pos].Info = Legitimate;
		H->Cells[Pos].Data = Key;
		return Pos;
	}
	else {
		printf("键值已存在");
		return Pos;
	}
}
IntHashTable CreateHashTable(int TableSize)
{
	IntHashTable H;
	int i;
	H = (IntHashTable)malloc(sizeof(struct IntTblNode));
	/* 保证散列表最大长度是素数 */
	H->TableSize = NextPrime(TableSize);
	/* 声明单元数组 */
	H->Cells = (Cell *)malloc(H->TableSize * sizeof(Cell));
	/* 初始化单元状态为“空单元” */
	for (i = 0; i < H->TableSize; i++) {
		H->Cells[i].Data = -1;
		H->Cells[i].Info = Empty;
	}

	return H;
}

void DestroyHashTable(IntHashTable table) {
	free(table->Cells);
	free(table);
}

void printPosition(int pos) {
	if (pos < 0) {
		printf("%s", "-");
	}
	else {
		printf("%d", pos);
	}

}

int SolveHashing()
{
	//N个记录
	int M, N;
	scanf("%d %d", &M, &N);
	IntHashTable table = CreateHashTable(M);
	for (int j = 0; j < N; j++) {
		int key;
		scanf("%d", &key);
		Position pos = Insert(table, key);
		printPosition(pos);
		if (j < N - 1) {
			printf(" ");
		}
	}
	return 0;
}
