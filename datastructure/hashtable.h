#pragma once
//开放地址法的散列表
#define MAXTABLESIZE 100000 /* 允许开辟的最大散列表长度 */
typedef char * ElementType;    /* 关键词类型用整型 */
typedef int Index;          /* 散列地址类型 */
typedef Index Position;     /* 数据所在位置与散列地址是同一类型 */
							/* 散列单元状态类型，分别对应：有合法元素、空单元、有已删除元素 */
typedef enum { Legitimate, Empty, Deleted } EntryType;
typedef struct HashEntry Cell; /* 散列表单元类型 */
struct HashEntry {
	ElementType Data; /* 存放元素 */
	EntryType Info;   /* 单元状态 */
	int Count; //重复插入次数
	//char *Mobile; //对应的手机号码
};
typedef struct TblNode *HashTable; /* 散列表类型 */
struct TblNode {   /* 散列表结点定义 */
	int TableSize; /* 表的最大长度 */
	Cell *Cells;   /* 存放散列单元数据的数组 */
};

char* GetSubstring(const char *strSource, const unsigned int uStartPos, const unsigned int uEndPos);

//返回大于N且不超过MAXTABLESIZE的最小素数
int NextPrime(int N);
//创建哈希表
HashTable CreateTable(int TableSize);
Position Hash(ElementType Key, int tableSize);
Position Find(HashTable H, ElementType Key);
bool Insert(HashTable H, ElementType Key);
void DestroyHashTable(HashTable table);