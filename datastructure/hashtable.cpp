#include "stdafx.h"
#include <math.h>
#include <stdlib.h>
#include "hashtable.h"
using namespace std;
#pragma warning(disable:4996)

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
