#pragma once
#define VALUELENGTH 16                   /* value字符串的最大长度 */
typedef int ElementType;				 /* key的类型 */
typedef char ValueType[VALUELENGTH+1];  /* value的类型 */

typedef int Index;                      /* 散列地址类型 */
/******** 以下是单链表的定义 ********/
typedef struct LNode *PtrToLNode;
struct LNode {
    //ElementType Data;
	ElementType Key;  //存放key
	ValueType Value; /* 存放value */
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;
/******** 以上是单链表的定义 ********/
typedef struct TblNode *LinkedHashTable; /* 散列表类型 */
struct TblNode {   /* 散列表结点定义 */
    int TableSize; /* 表的最大长度 */
    List Heads;    /* 指向链表头结点的数组 */
};

int HashByTableSize(ElementType Key, int tableSize);
LinkedHashTable CreateLinkedHashTable(int TableSize);
Position Find(LinkedHashTable H, ElementType Key);
bool Insert(LinkedHashTable H, ElementType Key, ValueType Value);
void DestroyTable(LinkedHashTable H);