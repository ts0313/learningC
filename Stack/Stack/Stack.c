#include "Stack.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

void CheckCapacity(Stack* ps) {
	assert(ps);
	if (ps->_size == ps->_capacity) {
		int newCapacity = ps->_capacity * 2;
		STDataType* pTemp = (STDataType*)malloc(sizeof(STDataType) * newCapacity);
		if (pTemp == NULL) {
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

void StackInit(Stack* ps) {
	assert(ps);
	ps->_array = (STDataType*)malloc(sizeof(STDataType) * 3);
	if (ps->_array == NULL) {
		assert(0);
		return;
	}
	ps->_capacity = 3;
	ps->_size = 0;
}

void StackPush(Stack* ps, STDataType data) {
	CheckCapacity(ps);
	ps->_array[ps->_size++] = data;
}

void StackPop(Stack* ps) {
	assert(ps);
	if (StackEmpty(ps)) {
		return;
	}
	ps->_size -= 1;
}

STDataType StackTop(Stack* ps) {
	assert(ps);
	return ps->_array[ps->_size - 1];
}

int StackSize(Stack* ps) {
	assert(ps);
	return ps->_size;
}

int StackEmpty(Stack* ps) {
	assert(ps);
	return 0 == ps->_size;
}

void StackDestory(Stack* ps) {
	assert(ps);
	if (ps->_array) {
		free(ps->_array);
		ps->_capacity = 0;
		ps->_size = 0;
	}
}

int main() {
	Stack s;
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPush(&s, 5);
	StackPush(&s, 8);
	StackDestory(&s);
	printf("size = %d\n", StackSize(&s));
	printf("top = %d\n", StackTop(&s));
	
	system("pause");
	return 0;
}