#include "Heap.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

void Swap(HPDataType* pLeft, HPDataType* pRight) {
	HPDataType tmp = *pLeft;
	*pLeft = *pRight;
	*pRight = tmp;
}

void AdjustDown(HPDataType* array, int size, int parent, PCOM Compare) {
	// 默认让child标记parent的左孩子
	int child = parent * 2 + 1;
	while (child < size) {
		// 找双亲孩子中最小的孩子
		if (child + 1 < size && Compare(array[child + 1], array[child])) {
			child += 1;
		}

		if (Compare(array[child], array[parent])) {
			Swap(&array[child], &array[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			return;
		}
	}
}

void AdjustUp(HPDataType* array, int size, int child, PCOM Compare) {
	int parent = (child - 1) / 2;
	while (child) {
		if (Compare(array[child], array[parent])) {
			Swap(&array[child], &array[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else {
			return;
		}
	}
}

void CheckCapacity(Heap* hp) {
	assert(hp);
	if (hp->_size == hp->_capacity) {
		int newCapacity = hp->_capacity * 2;
		HPDataType* pTemp = (HPDataType*)malloc(sizeof(HPDataType)*newCapacity);
		if (pTemp == NULL) {
			assert(0);
			return;
		}
		for (int i = 0; i < hp->_size; ++i) {
			pTemp[i] = hp->_array[i];
		}
		free(hp->_array);
		hp->_array = pTemp;
		hp->_capacity = newCapacity;
	}
}

int Less(HPDataType left, HPDataType right) {
	return left < right;
}

int Greater(HPDataType left, HPDataType right) {
	return left > right;
}

void InitHeap(Heap* hp, HPDataType* array, int size, PCOM compare) {
	assert(hp);
	hp->_array = (HPDataType*)malloc(sizeof(HPDataType)*size);
	if (hp->_array == NULL) {
		assert(0);
		return;
	}
	hp->_capacity = size;
	for (int i = 0; i < size; ++i) {
		hp->_array[i] = array[i];
	}
	hp->_size = size;
	hp->Compare = compare;
	int root = ((size - 2) >> 1);
	for (; root >= 0; --root) {
		AdjustDown(hp->_array, size, root, hp->Compare);
	}
}

void InitEmptyHeap(Heap* hp, int capacity, PCOM compare) {
	assert(hp);
	hp->_array = (HPDataType*)malloc(sizeof(HPDataType)*capacity);
	if (hp->_array == NULL) {
		assert(0);
		return;
	}
	hp->_capacity = capacity;
	hp->_size = 0;
	hp->Compare = compare;
}

void InsertHeap(Heap* hp, HPDataType data) {
	CheckCapacity(hp);
	hp->_array[hp->_size] = data;
	hp->_size++;
	AdjustDown(hp->_array, hp->_size, hp->_size - 1, hp->Compare);
}

void EraseHeap(Heap* hp) {
	if (HeapEmpty(hp)) {
		return;
	}
	Swap(&hp->_array[0], &hp->_array[hp->_size - 1]);
	hp->_size -= 1;
	AdjustDown(hp->_array, hp->_size, 0, hp->Compare);
}

int HeapSize(Heap* hp) {
	assert(hp);
	return hp->_size;
}

int HeapEmpty(Heap* hp) {
	assert(hp);
	return hp->_size == 0;
}

HPDataType HeapTop(Heap* hp) {
	assert(hp);
	return hp->_array[0];
}

void DestroyHeap(Heap* hp) {
	assert(hp);
	if (hp->_array) {
		free(hp->_array);
		hp->_capacity = 0;
		hp->_size = 0;
	}
}

void HeapAdjust(int* array, int size, int parent) {
	int child = parent * 2 + 1;
	while (child < size) {
		if (child + 1 < size && array[child + 1] > array[child]) {
			child += 1;
		}
		if (array[child] > array[parent]) {
			Swap(&array[child], &array[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			return;
		}
	}
}

void HeapSort(int* array, int size) {
	int root = ((size - 2) >> 1);
	for (; root >= 0; --root) {
		HeapAdjust(array, size, root);
	}
	int end = size - 1;
	while (end) {
		Swap(&array[0], &array[end]);
		HeapAdjust(array, end, 0);
		end--;
	}
}

int main() {
	Heap hp;
	int array[] = { 10, 5, 6 , 7 , 8 , 3 , 1 };
	InitHeap(&hp, array, sizeof(array) / sizeof(array[0]), Less);
	printf("%d\n", HeapSize(&hp));

	system("pause");
	return 0;
}