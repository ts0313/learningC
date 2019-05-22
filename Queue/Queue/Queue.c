#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

QNode* BuyQueueNode(QDatatype data) {
	QNode* pNewNode = (QNode*)malloc(sizeof(QNode));
	if (pNewNode == NULL) {
		assert(0);
		return NULL;
	}
	pNewNode->_data = data;
	pNewNode->_pNext = NULL;
	return pNewNode;
}

void QueueInit(Queue* q) {
	assert(q);
	q->_front = q->_back = NULL;
}

void QueuePush(Queue* q, QDatatype data) {
	assert(q);
	QNode* pNewNode = BuyQueueNode(data);
	if (QueueEmpty(q)) {
		q->_front = q->_back = pNewNode;
	}
	else {
		q->_back->_pNext = pNewNode;
		q->_back = pNewNode;
	}
}

void QueuePop(Queue* q) {
	QNode* pDelNode = NULL;
	if (QueueEmpty(q)) {
		return;
	}
	pDelNode = q->_front;
	if (pDelNode->_pNext == NULL) {
		q->_front = q->_back = NULL;
	}
	else {
		q->_front = pDelNode->_pNext;
	}
	free(pDelNode);
}

QDatatype QueueBack(Queue* q) {
	assert(q);
	return q->_back->_data;
}

QDatatype QueueFront(Queue* q) {
	assert(q);
	return q->_front->_data;
}

int QueueSize(Queue* q) {
	int count = 0;
	QNode* pCur = q->_front;
	while (pCur) {
		count++;
		pCur = pCur->_pNext;
	}
	return count;
}

int QueueEmpty(Queue* q) {
	assert(q);
	return q->_front == NULL;
}

void QueueDestory(Queue* q) {
	QNode* pCur = q->_front;
	while (pCur) {
		q->_front = pCur->_pNext;
		free(pCur);
		pCur = q->_front;
	}
	q->_front = q->_back = NULL;
}