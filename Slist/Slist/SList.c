#include "SList.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void SListInit(SList *s) {
	assert(s);
	s->_pHead = NULL;
}

PNode BuySListNode(SDataType data) {
	PNode pNewNode = (PNode)malloc(sizeof(Node));
	if (pNewNode == NULL) {
		assert(0);
		return NULL;
	}
	pNewNode->_data = data;
	pNewNode->_pNext = NULL;
	return pNewNode;
}

void SListPushBack(SList *s, SDataType data) {
	assert(s);
	PNode pNewNode = BuySListNode(data);
	if (s->_pHead == NULL) {
		//空链表
		s->_pHead = pNewNode;
	}
	else {
		//链表非空
		//找链表的最后一个结点
		PNode pCur = s->_pHead;
		while (pCur->_pNext) {
			pCur = pCur->_pNext;
		}
		pCur->_pNext = pNewNode;
	}
}

void SListPopBack(SList *s) {
	assert(s);
	if (s->_pHead == NULL) {
		return;
	}
	else if (s->_pHead->_pNext == NULL) {
		free(s->_pHead);
		s->_pHead = NULL;
	}
	else {
		PNode pPre = NULL;
		PNode pCur = s->_pHead;
		while (pCur->_pNext) {
			pPre = pCur;
			pCur = pCur->_pNext;
		}
		free(pCur);
		pPre->_pNext = NULL;
	}
}

void PrintSList(SList *s) {
	assert(s);
	PNode pCur = s->_pHead;
	while (pCur) {
		printf("%d--->", pCur->_data);
		pCur = pCur->_pNext;
	}
	printf("NULL\n");
}

void SListPushFront(SList *s, SDataType data) {
	assert(s);
	PNode pNewNode = BuySListNode(data);
	pNewNode->_pNext = s->_pHead;
	s->_pHead = pNewNode;
}

void SListPopFront(SList *s) {
	PNode pDelNode = NULL;
	assert(s);
	if (s->_pHead == NULL) {
		return;
	}
	//找到待删除的结点
	pDelNode = s->_pHead;
	s->_pHead = pDelNode->_pNext;
	free(pDelNode);
}

void SListInsert(PNode pos, SDataType data) {
	PNode pNewNode = NULL;
	if (pos == NULL) {
		return;
	}
	pNewNode = BuySListNode(data);
	pNewNode->_pNext = pos->_pNext;
	pos->_pNext = pNewNode;
}

void SListErase(SList *s, PNode pos) {
	assert(s);
	if (pos == NULL || s->_pHead == NULL) {
		return;
	}
	else {
		PNode pPrePos = s->_pHead;
		while (pPrePos && pPrePos->_pNext != pos) {
			pPrePos = pPrePos->_pNext;
		}
		if (pPrePos) {
			pPrePos->_pNext = pos->_pNext;
		}
	}
	free(pos);
}

PNode SListFind(SList *s, SDataType data) {
	assert(s);
	PNode pCur = s->_pHead;
	while (pCur) {
		if (pCur->_data == data) {
			return pCur;
		}
		pCur = pCur->_pNext;
	}
	return NULL;
}

int SListSize(SList *s) {
	assert(s);
	PNode pCur = s->_pHead;
	size_t count = 0;
	while (pCur) {
		count++;
		pCur = pCur->_pNext;
	}
	return count;
}

int  SListEmpty(SList *s) {
	assert(s);
	return s->_pHead == NULL;
}

void SListRemove(SList *s, SDataType data) {
	assert(s);
	if (s->_pHead == NULL) {
		return;
	}

	//找结点
	PNode pPre = NULL;
	PNode pCur = s->_pHead;
	while (pCur) {
		if (pCur->_data == data) {
			if (pCur == s->_pHead) {
				s->_pHead = pCur->_pNext;
			}
			else {
				pPre->_pNext = pCur->_pNext;
			}
			free(pCur);
			return;
		}
		else {
			pPre = pCur;
			pCur = pCur->_pNext;
		}
	}
}

int main() {
	SList s;
	SListInit(&s);
 	SListPushBack(&s, 1);
// 	SListPushBack(&s, 2);
// 	SListPushBack(&s, 3);
// 	SListPushBack(&s, 4);
// 	SListPushBack(&s, 5);
// 	SListPushBack(&s, 6);
// 	SListEmpty(&s);
	PrintSList(&s);
	system("pause");
	return 0;
}