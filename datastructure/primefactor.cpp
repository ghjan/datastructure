#include "stdafx.h"
#include "primefactor.h"

//��һ����n�ֽ�Ϊ���ɸ���С�������е������Ļ�
#include <iostream>
using namespace std;
int demo_primefactor()
{
	int n, n2;
	cin >> n;
	cout << n << "=";
	n2 = n;
	if(n<2)
		return 0;                //С��2�������Ϸ�����nΪ���������������
	for (int i = 2; i*i <= n2; i++)        //����n���Ӷ�
	{
		while (n2%i == 0)
		{
			n2 = n2 / i;
			cout << i;
			if (n2 != 1)cout << "*";
		}
	}
	if(n2!=1)cout << n2;        //��nΪ����
	return 0;
}