#pragma once

//顺序表是一段物理地址连续的存储单元,依次存储数据元素的线性结构
typedef int DataType;
typedef struct SeqList {
	DataType* _array;		//指向动态开辟的数组
	int _capacity;			//顺序表的总大小
	int _size;				//顺序表中有效元素的个数
}SeqList, *PSeq;

//初始化
void SeqListInit(PSeq ps, int capacity);
//尾插
void SeqListPushBack(PSeq ps, DataType data);
//删除尾部元素
void SeqListPopBack(PSeq ps);
//头插
void SeqListPushFront(PSeq ps, DataType data);
//删除头部元素
void SeqListPopFront(PSeq ps);
//在顺序表pos位置插入值为data的元素
void SeqListInsert(PSeq ps, int pos, DataType data);
//删除pos位置的元素
void SeqListErase(PSeq ps, int pos);
//在顺序表中查找值为data的元素,找到返回该元素的下标,否则返回-1
int SeqListFind(PSeq ps, DataType data);
//返回顺序表中有效元素的个数
int SeqListSize(PSeq ps);
//返回顺序表的容量大小
int SeqListCapacity(PSeq ps);
//检测顺序表是否为空,为空返回非0值
int SeqListEmpty(PSeq ps);
//将顺序表中的元素清空
void SeqListClear(PSeq ps);
//移除第一个值为data的元素
void SeqListRemove(PSeq ps, DataType data);
//移除所有值为data的元素
void SeqListRemoveAll(PSeq ps, DataType data);
//销毁顺序表
void SeqListDestory(PSeq ps);
//顺序表的扩容
void CheckCapacity(PSeq ps);
//打印顺序表
void SeqListPrint(PSeq ps);
//排序顺序表
void BubbSort(PSeq ps);