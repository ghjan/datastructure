#pragma once
#include "hashtable.h"

typedef Index Position;     /* 数据所在位置与散列地址是同一类型 */
							/* 散列单元状态类型，分别对应：有合法元素、空单元、有已删除元素 */

typedef int ElementType;    /* 关键词类型用整型 */
typedef struct HashEntry Cell; /* 散列表单元类型 */
struct HashEntry {
	ElementType Data; /* 存放元素 */
	EntryType Info;   /* 单元状态 */
};
typedef struct IntTblNode *IntHashTable; /* 散列表类型 */
struct IntTblNode {   /* 散列表结点定义 */
	int TableSize; /* 表的最大长度 */
	Cell *Cells;   /* 存放散列单元数据的数组 */
};


//创建哈希表
Position Hash(ElementType Key, int tableSize);
Position Find(IntHashTable H, ElementType Key);
Position Insert(IntHashTable H, ElementType Key);
IntHashTable CreateHashTable(int TableSize);
void DestroyHashTable(IntHashTable table);