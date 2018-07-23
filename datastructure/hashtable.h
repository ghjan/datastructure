#pragma once
//开放地址法的散列表
#define MAXTABLESIZE 100000 /* 允许开辟的最大散列表长度 */
typedef int Index;          /* 散列地址类型 */
typedef enum { Legitimate, Empty, Deleted } EntryType;
//返回大于N且不超过MAXTABLESIZE的最小素数
int NextPrime(int N);