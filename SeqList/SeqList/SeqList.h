#pragma once

//˳�����һ�������ַ�����Ĵ洢��Ԫ,���δ洢����Ԫ�ص����Խṹ
typedef int DataType;
typedef struct SeqList {
	DataType* _array;		//ָ��̬���ٵ�����
	int _capacity;			//˳�����ܴ�С
	int _size;				//˳�������ЧԪ�صĸ���
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
//��˳����в���ֵΪdata��Ԫ��,�ҵ����ظ�Ԫ�ص��±�,���򷵻�-1
int SeqListFind(PSeq ps, DataType data);
//����˳�������ЧԪ�صĸ���
int SeqListSize(PSeq ps);
//����˳����������С
int SeqListCapacity(PSeq ps);
//���˳����Ƿ�Ϊ��,Ϊ�շ��ط�0ֵ
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
void BubbSort(PSeq ps);