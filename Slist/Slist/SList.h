#pragma once

typedef int SDataType;

//链表的结点
typedef struct SListNode {
	SDataType _data;
	struct SListNode* _pNext;
}Node, *PNode;

typedef struct SList {
	PNode _pHead;			//指向链表中的第一个结点
}SList, *PSList;

//初始化链表
void SListInit(SList *s);
//尾插
void SListPushBack(SList *s, SDataType data);
//尾删
void SListPopBack(SList *s);
//头插
void SListPushFront(SList *s, SDataType data);
//头删
void SListPopFront(SList *s);
//在pos位置插入data
void SListInsert(PNode pos, SDataType data);
//删除pos位置的元素
void SListErase(SList *s, PNode pos);
//查找值为data的结点
PNode SListFind(SList *s, SDataType data);
//链表的有效元素个数
int SListSize(SList *s);
//链表为空则返回NULL
int SListEmpty(SList *s);
//移除第一个值为data的元素
void SListRemove(SList *s, SDataType data);
//移除所有值为data的元素
void SListRemoveAll(SList *s, SDataType data);