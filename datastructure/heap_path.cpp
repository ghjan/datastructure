
#include "stdafx.h"
#include <stdio.h>  
#include <stdlib.h>
#include "heap_path.h"

void Create()
{
	size = 0;
	H[0] = MINH;
	/*���á����ڡ�*/
}

void Insert(int X)
{
	/* ��X����H������ʡ�Լ����Ƿ������Ĵ��� */
	int i;
	for (i = ++size; H[i / 2] > X; i /= 2)
		H[i] = H[i / 2];
	H[i] = X;
}

//����·��
/*
��һϵ�и������ֲ���һ����ʼΪ�յ�С����H[]��
��������������±�`i`����ӡ��H[i]��������·����
### ��������:
5 3
46 23 26 24 10
5 4 3
### �������:
24 23 10
46 23 10
26 10
*/
int heap_path_demo()
{
	int n, m, x, i, j;
	scanf("%d %d", &n, &m);
	Create(); /* �ѳ�ʼ�� */
	for (i = 0; i<n; i++) { /*��������뷽ʽ���� */
		scanf("%d", &x);
		Insert(x);
	}
	for (i = 0; i<m; i++) {
		scanf("%d", &j);
		printf("%d", H[j]);
		while (j>1) { /*�ظ�������������*/
			j /= 2;
			printf(" %d", H[j]);
		}
		printf("\n");
	}
	return 0;
}