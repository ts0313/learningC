#include "SeqList.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void SeqListInit(PSeq ps, int capacity) {
	ps->_array = (DataType*)malloc(sizeof(DataType) * capacity);
	if (NULL == ps->_array) {
		assert(0);
		return;
	}
	ps->_capacity = capacity;
	ps->_size = 0;
}

void SeqListPushBack(PSeq ps, DataType data) {
	assert(ps);
	CheckCapacity(ps);
	ps->_array[ps->_size] = data;
	ps->_size++;
}

void SeqListPopBack(PSeq ps) {
	assert(ps);
	if (SeqListEmpty(ps)) {
		return;
	}
	ps->_size--;
}

void SeqListPushFront(PSeq ps, DataType data) {
	assert(ps);
	CheckCapacity(ps);
	//所有元素向后搬移一个位置
	for (int i = ps->_size - 1; i >= 0; i--) {
		ps->_array[i + 1] = ps->_array[i];
	}
	//插入元素
	ps->_array[0] = data;
	ps->_size++;
}

void SeqListPopFront(PSeq ps) {
	if (SeqListEmpty(ps)) {
		return;
	}
	//将所有元素向前搬移一个位置
	for (int i = 1; i < ps->_size; ++i) {
		ps->_array[i - 1] = ps->_array[i];
		ps->_size--;
	}
}

void SeqListInsert(PSeq ps, int pos, DataType data) {
	assert(ps);
	if (pos < 0) {
		return;
	}
	else if (pos > ps->_size) {
		CheckCapacity(ps);
	}
	//将pos位置元素以及pos位置以后的元素向后搬移一个位置
	for (int i = ps->_size - 1; i >= pos; i++) {
		ps->_array[i + 1] = ps->_array[i];
	}
	ps->_array[pos] = data;
	ps->_size++;
}

void SeqListErase(PSeq ps, int pos) {
	assert(ps);
	if (pos < 0 || pos >= ps->_size) {
		return;
	}
	for (int i = pos + 1; i < ps->_size; ++i) {
		ps->_array[i - 1] = ps->_array[i];
		ps->_size--;
	}
}

int SeqListFind(PSeq ps, DataType data) {
	assert(ps);
	for (int i = 0; i < ps->_size; ++i) {
		if (ps->_array[i] == data) {
			return i;
		}
	}
	return -1;
}

int SeqListSize(PSeq ps) {
	assert(ps);
	return ps->_size;
}

int SeqListCapacity(PSeq ps) {
	assert(ps);
	return ps->_capacity;
}

int SeqListEmpty(PSeq ps) {
	assert(ps);
	return 0 == ps->_size;
}

void SeqListClear(PSeq ps) {
	assert(ps);
	ps->_size = 0;
}

void SeqListRemove(PSeq ps, DataType data) {
	SeqListErase(ps, SeqListFind(ps, data));
}

void SeqListRemoveAll(PSeq ps, DataType data) {
	assert(ps);
	int count = 0;
	for (int i = 0; i < ps->_size; ++i) {
		if (ps->_array[i] == data) {
			count++;
		}
		else {
			ps->_array[i - count] = ps->_array[i];
		}
	}
	ps->_size -= count;
}

void SeqListDestory(PSeq ps) {
	if (ps->_array) {
		free(ps->_array);
		ps->_array = NULL;
		ps->_capacity = 0;
		ps->_size = 0;
	}
}

void CheckCapacity(PSeq ps) {
	assert(ps);
	if (ps->_size == ps->_capacity) {
		int newCapacity = ps->_capacity * 2;
		int* pTemp = (DataType*)malloc(newCapacity * sizeof(DataType));
		if (NULL == pTemp) {
			assert(0);
			return;
		}
		for (int i = 0; i < ps->_size; ++i) {
			pTemp[i] = ps->_array[i];
		}
		free(ps->_array);
		ps->_array = pTemp;
		ps->_capacity = newCapacity;
	}
}

void SeqListPrint(PSeq ps) {
	for (int i = 0; i < ps->_size; ++i) {
		printf("%d ", ps->_array[i]);
	}
	printf("\n");
}

void Swap(int *pLeft, int *pRight) {
	int temp = *pLeft;
	*pLeft = *pRight;
	*pRight = temp;
}

void BubbSort(PSeq ps) {
	for (int i = 0; i < ps->_size - 1; ++i) {
		int Ischange = 0;
		for (int j = 1; j < ps->_size - i; ++j) {
			Ischange = 1;
			Swap(&ps->_array[j - 1], &ps->_array[j]);
		}
	}
}