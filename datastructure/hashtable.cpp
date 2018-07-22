#include "stdafx.h"
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "hashtable.h"
using namespace std;
#pragma warning(disable:4996)
/***************************************************************
/*	函 数 名：GetSubstring
/*	函数功能：C语言版，获得字符串中指定位置的子串
/*	参    数：
/*			  strSource：源字符串
/*			  uStartPos：子串在源串的起始位置
/*			  uEndPos：  子串在源串的结束位置
/*	返 回 值：
/*			  如果成功，则返回子串
/*			  如果失败，则返回空串
/*
/*	作    者：X攻城狮
/*	日    期：2015年11月4日
/***************************************************************/
char* GetSubstring(const char *strSource, const unsigned int uStartPos, const unsigned int uEndPos)
{
	unsigned int uLen = strlen(strSource);
	if (uLen == 0)
	{
		return NULL;
	}
	char *strTemp = (char *)malloc(uLen + 1);
	memset(strTemp, 0, uLen + 1);
	strcpy(strTemp, strSource);

	if (uStartPos > uLen)
	{
		free(strTemp);
		return NULL;
	}

	uLen = uEndPos - uStartPos;
	char *strSub = (char *)malloc(uLen + 1);
	memset(strSub, 0, uLen + 1);

	unsigned int i;
	for (i = 0; i <= uLen; i++)
	{
		strSub[i] = strTemp[uStartPos + i];
	}
	strSub[i] = '\0';

	free(strTemp);

	return strSub;
}

//返回大于N且不超过MAXTABLESIZE的最小素数
int NextPrime(int N)
{
	int i, p = (N % 2) ? N + 2 : N + 1; /*从大于N的下一个奇数开始 */
	while (p <= MAXTABLESIZE) {
		for (i = (int)sqrt(p); i > 2; i--)
			if (!(p%i)) break; /* p不是素数 */
		if (i == 2) break; /* for正常结束，说明p是素数 */
		else  p += 2; /* 否则试探下一个奇数 */
	}
	return p;
}

HashTable CreateTable(int TableSize)
{
	HashTable H;
	int i;
	H = (HashTable)malloc(sizeof(struct TblNode));
	/* 保证散列表最大长度是素数 */
	H->TableSize = NextPrime(TableSize);
	/* 声明单元数组 */
	H->Cells = (Cell *)malloc(H->TableSize * sizeof(Cell));
	/* 初始化单元状态为“空单元” */
	for (i = 0; i < H->TableSize; i++) {
		H->Cells[i].Info = Empty;
		H->Cells[i].Data = NULL;
		H->Cells[i].Count = 0;
	}
	return H;
}
Position Hash(ElementType Key, int tableSize) {
	int number = atoi(GetSubstring(Key, 1, 3)) * 100000 + atoi((Key + 6));
	return number % tableSize;
}

Position Find(HashTable H, ElementType Key)
{
	Position CurrentPos, NewPos;
	int CNum = 0; /* 记录冲突次数 */
	NewPos = CurrentPos = Hash(Key, H->TableSize); /* 初始散列位置 */
												   /* 当该位置的单元非空，并且不是要找的元素时，发生冲突 */
	while (H->Cells[NewPos].Info != Empty && *H->Cells[NewPos].Data != *Key) {
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
	return NewPos; /* 此时NewPos或者是Key的位置，或者是一个空单元的位置（表示找不到）*/
}

bool Insert(HashTable H, ElementType Key)
{
	Position Pos = Find(H, Key); /* 先检查Key是否已经存在 */
	if (H->Cells[Pos].Info != Legitimate) { /* 如果这个单元没有被占，说明Key可以插入在此 */
		H->Cells[Pos].Info = Legitimate;
		H->Cells[Pos].Data = Key;
		//strcpy(H->Cells[Pos].Data, Key);
		H->Cells[Pos].Count = 1;
		/*字符串类型的关键词需要 strcpy 函数!! */
		return true;
	}
	else {
		//printf("键值已存在:%S\n", Key);
		H->Cells[Pos].Count++;
		return false;
	}
}

void DestroyHashTable(HashTable table) {
	for (int i = 0; i < table->TableSize; i++) {
		if (table->Cells[i].Data != NULL) {
			free(table->Cells[i].Data);
		}
	}
	free(table->Cells);
	free(table);
}

