#include "stdafx.h"
#include <stdlib.h>
#include <time.h> 

/*С��100�����������*/
int random_int()
{
	//�ı���������� 
	srand(time(0));
	int result = rand() % 100;
	int sig = result % 3 >0 ? 1 : -1;
	if (sig < 0)
		result = result / 2;
	return result * sig;
}