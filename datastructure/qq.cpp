#include "stdafx.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include "linkedhashtable.h"
using namespace std;
#pragma warning(disable:4996)

int SolveQQUser() {
	int N;
	scanf("%d\n", &N);

	LinkedHashTable table = CreateLinkedHashTable(N);
	char cmd[1];
	int u;
	ValueType password;
	Position pos = NULL;

	bool success = false;
	for (int count = 0; count < N && scanf("%s %d %s\n", &cmd, &u, password) != EOF; count++) {

		switch (cmd[0]) {
		case 'L':
			//login
			pos = Find(table, u);
			if (pos != NULL) { //存在key
				if (strcmp(pos->Value, password) == 0) {//相同Value 
					printf("Login: OK\n");
				}
				else {  //Value不符合
					printf("ERROR: Wrong PW\n");
				}
			}
			else { //不存在key
				printf("ERROR: Not Exist\n");
			}
			break;
		case 'N':
			//new user
			success = Insert(table, u, password);
			if (success) {
				printf("New: OK\n");
			}
			else {
				printf("ERROR: Exist\n");
			}
			break;
		default:
			printf("wrong cmd:%c", cmd);
			break;
		}
	}

	return 0;
}