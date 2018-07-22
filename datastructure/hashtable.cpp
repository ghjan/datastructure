#include "stdafx.h"
#include <math.h>
#include <stdlib.h>
#include "hashtable.h"
using namespace std;
#pragma warning(disable:4996)

//���ش���N�Ҳ�����MAXTABLESIZE����С����
int NextPrime(int N)
{
	int i, p = (N % 2) ? N + 2 : N + 1; /*�Ӵ���N����һ��������ʼ */
	while (p <= MAXTABLESIZE) {
		for (i = (int)sqrt(p); i > 2; i--)
			if (!(p%i)) break; /* p�������� */
		if (i == 2) break; /* for����������˵��p������ */
		else  p += 2; /* ������̽��һ������ */
	}
	return p;
}
