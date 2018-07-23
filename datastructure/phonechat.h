#pragma once
#include "hashtable.h"
typedef Index Position;     /* 数据所在位置与散列地址是同一类型 */
							/* 散列单元状态类型，分别对应：有合法元素、空单元、有已删除元素 */

typedef char * StrElementType;    /* 关键词类型用整型 */

typedef struct StringHashEntry StringCell; /* 散列表单元类型 */
struct StringHashEntry {
	StrElementType Data; /* 存放元素 */
	EntryType Info;   /* 单元状态 */
	int Count; //重复插入次数
			   //char *Mobile; //对应的手机号码
};
typedef struct StringTblNode *StringHashTable; /* 散列表类型 */
struct StringTblNode {   /* 散列表结点定义 */
	int TableSize; /* 表的最大长度 */
	StringCell *Cells;   /* 存放散列单元数据的数组 */
};

char* GetSubstring(const char *strSource, const unsigned int uStartPos, const unsigned int uEndPos);

//创建哈希表
StringHashTable CreateStringHashTable(int TableSize);
Position HashStringKey(StrElementType Key, int tableSize);
Position FindStringKey(StringHashTable H, StrElementType Key);
bool InsertStringHashTable(StringHashTable H, StrElementType Key);
void DestroyStringHashTable(StringHashTable table);