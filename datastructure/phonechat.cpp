#include "stdafx.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "phonechat.h"

using namespace std;
#pragma warning(disable:4996)

/***************************************************************
/*	�� �� ����GetSubstring
/*	�������ܣ�C���԰棬����ַ�����ָ��λ�õ��Ӵ�
/*	��    ����
/*			  strSource��Դ�ַ���
/*			  uStartPos���Ӵ���Դ������ʼλ��
/*			  uEndPos��  �Ӵ���Դ���Ľ���λ��
/*	�� �� ֵ��
/*			  ����ɹ����򷵻��Ӵ�
/*			  ���ʧ�ܣ��򷵻ؿմ�
/*
/*	��    �ߣ�X����ʨ
/*	��    �ڣ�2015��11��4��
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

StringHashTable CreateStringHashTable(int TableSize)
{
	StringHashTable H;
	int i;
	H = (StringHashTable)malloc(sizeof(struct StringTblNode));
	/* ��֤ɢ�б���󳤶������� */
	H->TableSize = NextPrime(TableSize);
	/* ������Ԫ���� */
	H->Cells = (StringCell *)malloc(H->TableSize * sizeof(StringCell));
	/* ��ʼ����Ԫ״̬Ϊ���յ�Ԫ�� */
	for (i = 0; i < H->TableSize; i++) {
		H->Cells[i].Info = Empty;
		H->Cells[i].Data = NULL;
		H->Cells[i].Count = 0;
	}
	return H;
}
Position HashStringKey(StrElementType Key, int tableSize) {
	int number = atoi(GetSubstring(Key, 1, 3)) * 100000 + atoi((Key + 6));
	return number % tableSize;
}

Position FindStringKey(StringHashTable H, StrElementType Key)
{
	Position CurrentPos, NewPos;
	int CNum = 0; /* ��¼��ͻ���� */
	NewPos = CurrentPos = HashStringKey(Key, H->TableSize); /* ��ʼɢ��λ�� */
												   /* ����λ�õĵ�Ԫ�ǿգ����Ҳ���Ҫ�ҵ�Ԫ��ʱ��������ͻ */
	while (H->Cells[NewPos].Info != Empty && !strcmp(H->Cells[NewPos].Data, Key) ) {
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
	return NewPos; /* ��ʱNewPos������Key��λ�ã�������һ���յ�Ԫ��λ�ã���ʾ�Ҳ�����*/
}

bool InsertStringHashTable(StringHashTable H, StrElementType Key)
{
	Position Pos = FindStringKey(H, Key); /* �ȼ��Key�Ƿ��Ѿ����� */
	if (H->Cells[Pos].Info != Legitimate) { /* ��������Ԫû�б�ռ��˵��Key���Բ����ڴ� */
		H->Cells[Pos].Info = Legitimate;
		H->Cells[Pos].Data = Key;
		//strcpy(H->Cells[Pos].Data, Key);
		H->Cells[Pos].Count = 1;
		/*�ַ������͵Ĺؼ�����Ҫ strcpy ����!! */
		return true;
	}
	else {
		//printf("��ֵ�Ѵ���:%S\n", Key);
		H->Cells[Pos].Count++;
		return false;
	}
}

void DestroyStringHashTable(StringHashTable table) {
	for (int i = 0; i < table->TableSize; i++) {
		if (table->Cells[i].Data != NULL) {
			free(table->Cells[i].Data);
		}
	}
	free(table->Cells);
	free(table);
}


StringHashTable ReadPhoneCallRecord()
{
	//N����¼
	int N;
	scanf("%d", &N);
	StringHashTable table = CreateStringHashTable(N * 2);
	for (int j = 0; j < N; j++) {
		StrElementType key = (StrElementType)malloc(11 * sizeof(char));
		scanf("%s", key);
		InsertStringHashTable(table, key);
		key = (StrElementType)malloc(11 * sizeof(char));
		scanf("%s", key);
		InsertStringHashTable(table, key);
	}
	return table;
}

void ScanAndOutput(StringHashTable table) {

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
			else if (table->Cells[i].Count == maxCallCount) { //���йھ�
				if (atoi(table->Cells[i].Data) < atoi(mobileCrazy)) { //ȡ��С��
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
	StringHashTable table = ReadPhoneCallRecord();
	ScanAndOutput(table);
	DestroyStringHashTable(table);
	return 0;
}