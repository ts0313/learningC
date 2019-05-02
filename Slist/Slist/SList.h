#pragma once

typedef int SDataType;

//����Ľ��
typedef struct SListNode {
	SDataType _data;
	struct SListNode* _pNext;
}Node, *PNode;

typedef struct SList {
	PNode _pHead;			//ָ�������еĵ�һ�����
}SList, *PSList;

//��ʼ������
void SListInit(SList *s);
//β��
void SListPushBack(SList *s, SDataType data);
//βɾ
void SListPopBack(SList *s);
//ͷ��
void SListPushFront(SList *s, SDataType data);
//ͷɾ
void SListPopFront(SList *s);
//��posλ�ò���data
void SListInsert(PNode pos, SDataType data);
//ɾ��posλ�õ�Ԫ��
void SListErase(SList *s, PNode pos);
//����ֵΪdata�Ľ��
PNode SListFind(SList *s, SDataType data);
//�������ЧԪ�ظ���
int SListSize(SList *s);
//����Ϊ���򷵻�NULL
int SListEmpty(SList *s);
//�Ƴ���һ��ֵΪdata��Ԫ��
void SListRemove(SList *s, SDataType data);
//�Ƴ�����ֵΪdata��Ԫ��
void SListRemoveAll(SList *s, SDataType data);