#pragma once
typedef int STDataType;

typedef struct Stack {
	STDataType* _array;
	int _capacity;
	int _size;	
}Stack;

void StackInit(Stack* ps);
void StackPush(Stack* ps, STDataType data);
void StackPop(Stack* ps);
int StackSize(Stack* ps);
int StackEmpty(Stack* ps);
void StackDestory(Stack* ps);
void CheckCapacity(Stack* ps);
STDataType StackTop(Stack* ps);