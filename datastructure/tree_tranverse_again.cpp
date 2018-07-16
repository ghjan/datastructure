#include "stdafx.h"
#include <iostream>
using namespace std;
#include "BinarySearchTree.h"

void read_file_test(const char *file_name)
{
	char c[1000];
	FILE *fptr;

	if ((fptr = fopen(file_name, "r")) == NULL)
	{
		printf("Error! opening file");
		// �ļ�ָ�뷵�� NULL ���˳�
		exit(1);
	}
	
	while (fscanf(fptr, "%[^\n]", c) != EOF) {// ��ȡ�ı���ֱ�������µ�һ�п�ʼ
		fgetc(fptr); //��ȡ�����ַ�
		printf("��ȡ����:%s\n", c);
	}

	fclose(fptr);
}

int tree_tranverse_again_demo()
{
	const char   *month[] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
	BinarySearchTree *root = NULL;
	for (int i = 0; i < 12; i++) {
		if (i == 0)
			root = insert(month[i], root);
		else {
			BinarySearchTree *tree = root;
			insert(month[i], tree);
		}
	}
	examine(root);

	remove(month[2], root);
	examine(root);
	remove(month[3], root);
	examine(root);
	remove(month[8], root);
	examine(root);

	return 0;
}

void tree_tranverse_again_demo1() {
	read_file_test("tree_tranverse_again.txt");
}
