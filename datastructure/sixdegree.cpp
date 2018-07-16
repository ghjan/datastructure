#include "stdafx.h"
//#include <bits/stdc++.h>
#include <stdio.h>  
#include <stdlib.h>  
#include<queue>
#include<cmath>
#include "sixdegree.h"

using namespace std;

/*
数据结构与算法题目集（中文） - 7-7 六度空间
https://blog.csdn.net/dream_weave/article/details/80870033
*/

//某个顶点对应的六度空间的结果
//返回一个百分制的分数
int bfsSixDegree(int index)
{
	// 最后一个结点，尾巴，每个点的最终结果，6层范围内的数，临时节点
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
			if (mp[tmp][i] && !vis[i]) // 有边且未被访问过
			{
				cnt++;
				vis[i] = 1;
				tail = i; // 为了每一层最后一个的节点标记
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
	//    mem(mp,0); // 内存超限
	int u, v;
	for (int i = 0; i<m; i++)
	{
		scanf("%d%d", &u, &v);
		mp[u][v] = mp[v][u] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		mem(vis, 0); //清空
		printf("%d: %.2f%%\n", i, bfsSixDegree(i)*100.0 / n);
	}
	char c;
	scanf("%c", &c);
	return 0;
}
