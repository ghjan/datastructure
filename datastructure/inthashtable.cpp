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
	int CNum = 0; /* ��¼��ͻ���� */
	NewPos = CurrentPos = Hash(Key, H->TableSize); /* ��ʼɢ��λ�� */
												   /* ����λ�õĵ�Ԫ�ǿգ����Ҳ���Ҫ�ҵ�Ԫ��ʱ��������ͻ */
	while (H->Cells[NewPos].Info != Empty && H->Cells[NewPos].Data != Key && CNum < H->TableSize) {
		/* �ַ������͵Ĺؼ�����Ҫ strcmp ����!! */
		/* ͳ��1�γ�ͻ�����ж���ż�� */
		if (++CNum % 2) { /* �����γ�ͻ */
			NewPos = CurrentPos + (CNum + 1)*(CNum + 1) / 4; /* ����Ϊ+[(CNum+1)/2]^2 */
			if (NewPos >= H->TableSize)
				NewPos = NewPos % H->TableSize; /* ����Ϊ�Ϸ���ַ */
		}
		else { /* ż���γ�ͻ */
			NewPos = CurrentPos - CNum * CNum / 4; /* ����Ϊ-(CNum/2)^2 */
			while (NewPos < 0)
				NewPos += H->TableSize; /* ����Ϊ�Ϸ���ַ */
		}
	}
	if (CNum >= H->TableSize) {
		return -1;
	}
	return NewPos; /* ��ʱNewPos������Key��λ�ã�������һ���յ�Ԫ��λ�ã���ʾ�Ҳ�����*/
}

Position FindLinear(IntHashTable H, ElementType Key)
{
	Position CurrentPos, NewPos;
	int CNum = 0; /* ��¼��ͻ���� */
	NewPos = CurrentPos = Hash(Key, H->TableSize); /* ��ʼɢ��λ�� */
												   /* ����λ�õĵ�Ԫ�ǿգ����Ҳ���Ҫ�ҵ�Ԫ��ʱ��������ͻ */
	while (H->Cells[NewPos].Info != Empty && H->Cells[NewPos].Data != Key && CNum < H->TableSize) {
		NewPos = (CurrentPos + CNum + 1) % H->TableSize;
	}
	if (CNum >= H->TableSize) {
		return -1;
	}
	return NewPos; /* ��ʱNewPos������Key��λ�ã�������һ���յ�Ԫ��λ�ã���ʾ�Ҳ�����*/
}
Position Insert(IntHashTable H, ElementType Key)
{
	Position Pos = Find(H, Key); /* �ȼ��Key�Ƿ��Ѿ����� */
	if (H->Cells[Pos].Info != Legitimate) { /* ��������Ԫû�б�ռ��˵��Key���Բ����ڴ� */
		H->Cells[Pos].Info = Legitimate;
		H->Cells[Pos].Data = Key;
		/*�ַ������͵Ĺؼ�����Ҫ strcpy ����!! */
		return Pos;
	}
	else {
		printf("��ֵ�Ѵ���");
		return Pos;
	}
}

Position InsertLinear(IntHashTable H, ElementType Key)
{
	Position Pos = FindLinear(H, Key); /* �ȼ��Key�Ƿ��Ѿ����� */
	if (Pos < 0)
		return Pos;
	if (H->Cells[Pos].Info != Legitimate) { /* ��������Ԫû�б�ռ��˵��Key���Բ����ڴ� */
		H->Cells[Pos].Info = Legitimate;
		H->Cells[Pos].Data = Key;
		return Pos;
	}
	else {
		printf("��ֵ�Ѵ���");
		return Pos;
	}
}
IntHashTable CreateHashTable(int TableSize)
{
	IntHashTable H;
	int i;
	H = (IntHashTable)malloc(sizeof(struct IntTblNode));
	/* ��֤ɢ�б���󳤶������� */
	H->TableSize = NextPrime(TableSize);
	/* ������Ԫ���� */
	H->Cells = (Cell *)malloc(H->TableSize * sizeof(Cell));
	/* ��ʼ����Ԫ״̬Ϊ���յ�Ԫ�� */
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
	//N����¼
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
