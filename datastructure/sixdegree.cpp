#include "stdafx.h"
//#include <bits/stdc++.h>
#include <stdio.h>  
#include <stdlib.h>  
#include<queue>
#include<cmath>
#include "sixdegree.h"

using namespace std;

/*
���ݽṹ���㷨��Ŀ�������ģ� - 7-7 ���ȿռ�
https://blog.csdn.net/dream_weave/article/details/80870033
*/

//ĳ�������Ӧ�����ȿռ�Ľ��
//����һ���ٷ��Ƶķ���
int bfsSixDegree(int index)
{
	// ���һ����㣬β�ͣ�ÿ��������ս����6�㷶Χ�ڵ�������ʱ�ڵ�
	int last = index, tail = 0, cnt = 1, lvl = 0, tmp;
	vis[index] = 1;
	queue<int> que;
	que.push(index);
	while (!que.empty())
	{
		tmp = que.front();//Returns a reference to the next element in the queue.
		que.pop();
		for (int i = 1; i <= n; i++)
		{
			if (mp[tmp][i] && !vis[i]) // �б���δ�����ʹ�
			{
				cnt++;
				vis[i] = 1;
				tail = i; // Ϊ��ÿһ�����һ���Ľڵ���
				que.push(i);
			}
		}

		if (tmp == last)
		{
			last = tail;
			lvl++;
		}

		if (lvl == 6) break;
	}
	return cnt;
}

int sixdegree_demo()
{
	scanf("%d%d", &n, &m);
	//    mem(mp,0); // �ڴ泬��
	int u, v;
	for (int i = 0; i<m; i++)
	{
		scanf("%d%d", &u, &v);
		mp[u][v] = mp[v][u] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		mem(vis, 0); //���
		printf("%d: %.2f%%\n", i, bfsSixDegree(i)*100.0 / n);
	}
	char c;
	scanf("%c", &c);
	return 0;
}
