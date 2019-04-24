#pragma once

typedef int DataType;
typedef struct SeqList
{
	DataType* _array;
	int _capacity; // ˳�����ܴ�С
	int _size; // ˳�������ЧԪ�صĸ���
}SeqList, *PSeq;


//��ʼ��
void SeqListInit(PSeq ps, int capacity);
//β��
void SeqListPushBack(PSeq ps, DataType data);
//ɾ��β��Ԫ��
void SeqListPopBack(PSeq ps);
//ͷ��
void SeqListPushFront(PSeq ps, DataType data);
//ɾ��ͷ��Ԫ��
void SeqListPopFront(PSeq ps);	
//��˳���posλ�ò���ֵΪdata��Ԫ��
void SeqListInsert(PSeq ps, int pos, DataType data);
//ɾ��posλ�õ�Ԫ��
void SeqListErase(PSeq ps, int pos);
//��˳����в���ֵΪdata��Ԫ�أ��ҵ����ظ�Ԫ����˳����е��±꣬���򷵻�-1
int SeqListFind(PSeq ps, DataType data);
//����˳�������ЧԪ�صĸ���
int SeqListSize(PSeq ps);
//����˳����������С
int SeqListCapacity(PSeq ps);
//���˳����Ƿ�Ϊ�գ����Ϊ�շ��ط�0ֵ���ǿշ���0
int SeqListEmpty(PSeq ps);
//��˳����е�Ԫ�����
void SeqListClear(PSeq ps);
//�Ƴ���һ��ֵΪdata��Ԫ��
void SeqListRemove(PSeq ps, DataType data);
//�Ƴ�����ֵΪdata��Ԫ��
void SeqListRemoveAll(PSeq ps, DataType data);
//����˳���
void SeqListDestory(PSeq ps);
//˳��������
void CheckCapacity(PSeq ps);
//��ӡ˳���
void SeqListPrint(PSeq ps);
//����˳���
void BubbleSort(PSeq ps);