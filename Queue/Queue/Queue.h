#pragma once
typedef int QDatatype;

typedef struct QNode {
	struct QNode* _pNext;
	QDatatype _data;
}QNode;

typedef struct Queue {
	QNode* _front;
	QNode* _back;
}Queue;

void QueueInit(Queue* q);
void QueuePush(Queue* q, QDatatype data);
void QueuePop(Queue* q);
QDatatype QueueFront(Queue* q);
QDatatype QueueBack(Queue* q);
int QueueSize(Queue* q);
int QueueEmpty(Queue* q);
void QueueDestory(Queue* q);