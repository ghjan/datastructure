#include "stdafx.h"
#include <stdlib.h>
#include <time.h> 

/*小于100的随机数函数*/
int random_int()
{
	//改变随机数种子 
	srand(time(0));
	int result = rand() % 100;
	int sig = result % 3 >0 ? 1 : -1;
	if (sig < 0)
		result = result / 2;
	return result * sig;
}