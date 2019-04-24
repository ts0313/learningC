//��̬˳���
#include "SeqList.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//˳����ʼ��
void SeqListInit(PSeq ps, int capacity) {
	ps->_array = (DataType*)malloc(sizeof(DataType)*capacity);
	if (NULL == ps->_array) {
		assert(0);
		return;
	}
	ps->_capacity = capacity;
	ps->_size = 0;
}

//��˳����β������ֵΪdata��Ԫ��
void SeqListPushBack(PSeq ps, DataType data) {
#if 0
	assert(ps);
	//˳�����
	//CheckCapacity(ps);

	ps->_array[ps->_size] = data;
	ps->_size++;
#endif
	SeqListInsert(ps, ps->_size, data);
}

//ɾ��˳������һ��Ԫ��
void SeqListPopBack(PSeq ps) {
#if 0
	assert(ps);
	if (SeqListEmpty(ps))
		return;

	ps->_size--;
#endif
	SeqListErase(ps, ps->_size - 1);
}

//��˳����ͷ������ֵΪdata��Ԫ�� 
void SeqListPushFront(PSeq ps, DataType data) {
#if 0
	assert(ps);
	//CheckCapacity(ps);

	//��˳�������Ԫ��ͳһ������һ��λ��
	for (int i = ps->_size - 1; i >= 0; i--) {
		ps->_array[i + 1] = ps->_array[i];
	}
	//����Ԫ��
	ps->_array[0] = data;
	ps->_size++;
#endif
	SeqListInsert(ps, 0, data);
}

//ɾ��˳���ͷ����Ԫ��
void SeqListPopFront(PSeq ps) {
#if 0
	if (SeqListEmpty(ps))
		return;
	for (int i = 1; i < ps->_size; ++i)
		ps->_array[i - 1] = ps->_array[i];
	ps->_size--;
#endif
	SeqListErase(ps, 0);
}

//��˳���posλ�ò���ֵΪdata��Ԫ�� 
void SeqListInsert(PSeq ps, int pos, DataType data) {
	assert(ps);
	if (pos < 0 || pos > ps->_size)
		return;
	CheckCapacity(ps);
	for (int i = ps->_size - 1; i >= pos; i--)
		ps->_array[i + 1] = ps->_array[i];
	ps->_array[pos] = data;
	ps->_size++;
}

//ɾ��˳�����posλ���ϵ�Ԫ��
void SeqListErase(PSeq ps, int pos) {
	assert(ps);
	if (pos < 0 || pos >= ps->_size)
		return;
	for (int i = pos + 1; i < ps->_size; ++i)
		ps->_array[i - 1] = ps->_array[i];
	ps->_size--;
}

//��˳����в���ֵΪdata��Ԫ�أ��ҵ����ظ�Ԫ����˳����е��±꣬���򷵻�-1 
int SeqListFind(PSeq ps, DataType data) {
	assert(ps);
	for (int i = 0; i < ps->_size; i++) {
		if (ps->_array[i] == data)
			return i;
	}
	return -1;
}

//����˳�������ЧԪ�صĸ��� 
int SeqListSize(PSeq ps) {
	assert(ps);
	return ps->_size;
}

//����˳����������С 
int SeqListCapacity(PSeq ps) {
	assert(ps);
	return ps->_capacity;
}

//���˳����Ƿ�Ϊ�գ����Ϊ�շ��ط�0ֵ���ǿշ���0 
int SeqListEmpty(PSeq ps) {
	assert(ps);
	return 0 == ps->_size;
}

//��˳����е�Ԫ�����
void SeqListClear(PSeq ps) {
	assert(ps);
	ps->_size = 0;
}

//�Ƴ���һ��ֵΪdata��Ԫ��
void SeqListRemove(PSeq ps, DataType data) {
	SeqListErase(ps, SeqListFind(ps, data));
}

//�Ƴ�����ֵΪdata��Ԫ��
void SeqListRemoveAll(PSeq ps, DataType data) {
	assert(ps);
	int count = 0;
	for (int i = 0; i < ps->_size; ++i) {
		if (ps->_array[i] == data)
			count++;
		else
			ps->_array[i - count] = ps->_array[i];
	}
	ps->_size -= count;
}

//����˳��� 
void SeqListDestory(PSeq ps) {
	if (ps->_array) {
		free(ps->_array);
		ps->_array = NULL;
		ps->_capacity = 0;
		ps->_size = 0;
	}
}

//˳��������
void CheckCapacity(PSeq ps) {
	assert(ps);
	if (ps->_size == ps->_capacity) {
		//˳���û�пռ���
		int newCapacity = ps->_capacity * 2;
		//realloc(p, size)
		//�����¿ռ�
		int* pTemp = (DataType*)malloc(newCapacity * sizeof(DataType));
		if (NULL == pTemp) {
			assert(0);
			return;
		}
		//����Ԫ��memcpy
		for (int i = 0; i < ps->_size; ++i)
			pTemp[i] = ps->_array[i];
		//�ͷžɿռ�
		free(ps->_array);
		//����
		ps->_array = pTemp;
		ps->_capacity = newCapacity;
	}
}

void SeqListPrint(PSeq ps) {
	for (int i = 0; i < ps->_size; ++i)
		printf("%d ", ps->_array[i]);
	printf("\n");
}

//////////////////////////////////////
void Swap(int* pLeft, int* pRight) {
	int temp = *pLeft;
	*pLeft = *pRight;
	*pRight = temp;
}

//ð������
void BubbleSort(PSeq ps) {
	//N----->N-1
	for (int i = 0; i < ps->_size - 1; ++i) {		//����ð���ܵ�����
		int Ischange = 0;
		//ð�ݵľ��巽ʽ: �����ڵ�����Ԫ�ؽ��бȽ�,������Ҫ����
		for (int j = 1; j < ps->_size - i; ++j) {
			if (ps->_array[j - 1] > ps->_array[j]) {
				Ischange = 1;
				Swap(&ps->_array[j - 1], &ps->_array[j]);
			}
		}
		if (!Ischange)
			return;
	}
}

//int BinarySearch(PSeq ps, DataType data);
//
//void TestSeqList() {
//	SeqList s;
//	int pos = -1;
//	SeqListInit(&s, 10);
//	SeqListPushBack(&s, 1);
//	SeqListPushBack(&s, 2);
//	SeqListPushBack(&s, 3);
//	SeqListPushBack(&s, 4);
//	SeqListPushBack(&s, 5);
//	SeqListPushBack(&s, 6);
//	SeqListPushBack(&s, 7);
//	SeqListPushBack(&s, 8);
//	SeqListPushBack(&s, 9);
//	SeqListPushBack(&s, 0);
//	printf("size = %d\n", SeqListSize(&s));
//	printf("capacity = %d\n", SeqListCapacity(&s));
//	SeqListPrint(&s);
//
//	SeqListPushBack(&s, 1);
//	printf("size = %d\n", SeqListSize(&s));
//	printf("capacity = %d\n", SeqListCapacity(&s));
//	SeqListPrint(&s);
//
//	SeqListPopBack(&s);
//	SeqListPrint(&s);
//
//	SeqListPushFront(&s, 0);
//	SeqListPrint(&s);
//
//	SeqListPopFront(&s);
//	SeqListPrint(&s);
//
//	SeqListInsert(&s, 1, 5);
//	SeqListPrint(&s);
//
//	pos = SeqListFind(&s, 5);
//	if (pos != -1)
//		printf("5 is in %d!!!\n", pos);
//	else
//		printf("5 is not in %d!!!\n", pos);
//
//	SeqListErase(&s, 1);
//
//	pos = SeqListFind(&s, 5);
//
//	if (pos != -1)
//		printf("5 is in %d!!!\n", pos);
//	else
//		printf("5 is not in %d!!!\n", pos);
//
//	SeqListPrint(&s);
//	printf("size = %d\n", SeqListSize(&s));
//	printf("capacity = %d\n", SeqListCapacity(&s));
//
//	SeqListDestory(&s);
//}

int main() {

	SeqList s;
	SeqListInit(&s, 10);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 7);
	SeqListPushBack(&s, 8);
	SeqListPushBack(&s, 9);
	SeqListPushBack(&s, 0);
	SeqListPushBack(&s, 1);
	BubbleSort(&s);
	SeqListRemoveAll(&s, 1);
	SeqListPrint(&s);
	printf("i = %d\n", SeqListFind(&s, 6));
	printf("size = %d\n", SeqListSize(&s));
	printf("capacity = %d\n", SeqListCapacity(&s));
	system("pause");
	return 0;
}