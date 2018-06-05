#include "stdafx.h"
#include "primefactor.h"

//将一个数n分解为若干个从小到大排列的质数的积
#include <iostream>
using namespace std;
int demo_primefactor()
{
	int n, n2;
	cin >> n;
	cout << n << "=";
	n2 = n;
	if(n<2)
		return 0;                //小于2的数不合法，若n为质数则输出它本身
	for (int i = 2; i*i <= n2; i++)        //根号n复杂度
	{
		while (n2%i == 0)
		{
			n2 = n2 / i;
			cout << i;
			if (n2 != 1)cout << "*";
		}
	}
	if(n2!=1)cout << n2;        //当n为质数
	return 0;
}