#pragma once
#pragma warning(disable:4996)
#define mem(a,b) memset(a,b,sizeof a);

typedef long long ll;

const int maxn = 10005;

//�Ƿ���ʹ��ı��; �����Ȩ�صľ���
int vis[maxn], mp[maxn][maxn];
int n, m;//������������
int bfsSixDegree(int len);//ĳ�������Ӧ�����ȿռ�Ľ��