#include "stdafx.h"
#include <stdlib.h>
#include <time.h> 
#include "utils.h"

/*С��100�����������*/
int random_int()
{
	//�ı���������� 
	srand(time(0));
	int result = rand() % 100;
	int sig = result % 3 > 0 ? 1 : -1;
	if (sig < 0)
		result = result / 2;
	return result * sig;
}

int Compare(int a, int b)
{
	if (a > b)
	{
		return 1;
	}
	if (a == b)
	{
		return 0;
	}
	if (a < b)
		return -1;
}