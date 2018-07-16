#pragma once
#pragma warning(disable:4996)
#define mem(a,b) memset(a,b,sizeof a);

typedef long long ll;

const int maxn = 10005;

//是否访问过的标记; 保存边权重的矩阵
int vis[maxn], mp[maxn][maxn];
int n, m;//顶点数，边数
int bfsSixDegree(int len);//某个顶点对应的六度空间的结果