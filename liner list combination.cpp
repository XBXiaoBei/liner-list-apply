#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h> 
#include<Windows.h>
#include<time.h>
#include<malloc.h>

typedef struct student
{
	char name[20];
	double score;
}ElemType;

typedef struct dnode
{
	ElemType data;
	struct dnode* next;
}LNode, * LinkList;

void twoLinkList1(LinkList L1, LinkList L2)
{
	LinkList p1, q1, p2, q2;
	q1 = L1;
	p1 = L1->next;
	p2 = L2->next;
	q2 = p2->next;
	while (p1 && p2) {
		if (p1->data.score >= p2->data.score) {
			p2->next = p1;
			q1->next = p2;
			p1 = p2;
			p2 = q2;
			q2 = p2->next;
		}
		else {
			q1 = p1;
			p1 = p1->next;
		}
	}
	if (p2) {
		q1->next = p2;
	}
	free(L2);
}

int twoLinkList2(LinkList L1, LinkList L2, LinkList* L3)
{
	LinkList p1, p2, p3, s;
	p1 = L1->next;
	p2 = L2->next;
	if ((*L3 = (LinkList)malloc(sizeof(LNode))) == NULL)
		return 0;
	(*L3)->next == NULL;
	p3 = *L3;
	while (p1 && p2) {
		if (p1->data.score <= p2->data.score) {
			s = (LinkList)malloc(sizeof(LNode));
			if (s == NULL)
				return 0;
			s->next = NULL;
			s->data = p1->data;
			p1 = p1->next;

			p3->next = s;
			p3 = s;
		}
		else {
			s = (LinkList)malloc(sizeof(LNode));
			if (s == NULL)
				return 0;
			s->next = NULL;
			s->data = p2->data;
			p2 = p2->next;

			p3->next = s;
			p3 = s;
		}
	}
	while (p1) {
		s = (LinkList)malloc(sizeof(LNode));
		if (s == NULL)
			return 0;
		s->next = NULL;
		s->data = p1->data;
		p1 = p1->next;

		p3->next = s;
		p3 = s;
	}
	while (p2) {
		s = (LinkList)malloc(sizeof(LNode));
		if (s == NULL)
			return 0;
		s->next = NULL;
		s->data = p2->data;
		p2 = p2->next;

		p3->next = s;
		p3 = s;
	}
	return 1;
}

int main()
{

	return 0;
}