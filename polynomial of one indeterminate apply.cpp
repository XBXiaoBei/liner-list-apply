#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h> 
#include<Windows.h>
#include<time.h>
#include<malloc.h>

typedef struct {
	double coef;
	int exp;
}Term;

typedef struct Pnode {
	Term data;
	struct Pnode* next;
}PNode, * PLink;

void insertPolyn(PLink L, Term term_insert)    //polynnomial
{
	PLink PLink_Comp_pre = L, PLink_Comp = L->next, PLink_Insert;
	while (PLink_Comp != NULL && term_insert.exp > PLink_Comp->data.exp) {
		PLink_Comp_pre = PLink_Comp;
		PLink_Comp = PLink_Comp->next;
	}
	if (PLink_Comp != NULL && term_insert.exp == PLink_Comp->data.exp) {
		if (fabs(term_insert.coef + PLink_Comp->data.coef) < 1E-6) {
			PLink_Comp_pre->next = PLink_Comp->next;
		}
		else {
			PLink_Comp->data.coef = PLink_Comp->data.coef + term_insert.coef;
		}
	}
	else {
		if ((PLink_Insert = (PLink)malloc(sizeof(PNode))) == NULL)
			return;
		PLink_Insert->data = term_insert;
		PLink_Insert->next = PLink_Comp;
		PLink_Comp_pre->next = PLink_Insert;
	}
	return;
}

int creatPLink(PLink* L)
{
	Term X;
	if ((*L = (PLink)malloc(sizeof(PNode))) == NULL)
		return 0;
	(*L)->next = NULL;
	do {
		printf("请输入系数和指数，用空格个靠，系数为0表示结束：");
		int c = scanf("%lf %d", &X.coef, &X.exp);
		if (fabs(X.coef) < 1E-6) {
			break;
		}
		insertPolyn(*L, X);
	} while (1);
	return 1;
}

int addPolyn(PLink L1, PLink L2, PLink* L3)
{
	PLink p1 = L1->next, p2 = L2->next, p3;
	(*L3) = (PLink)malloc(sizeof(PNode));
	if (*L3 == NULL)
		return 0;
	(*L3)->next = NULL;
	while (p1 && p2) {
		if (p1->data.exp < p2->data.exp) {
			insertPolyn(*L3, p1->data);
			p1 = p1->next;
		}
		else {
			insertPolyn(*L3, p2->data);
			p2 = p2->next;
		}
	}
	p3 = *L3;
	while (p3->next != NULL) {
		p3 = p3->next;
	}
	if (p1) {
		p3->next = p1;
	}
	if (p2) {
		p3->next = p2;
	}
	return 1;
}

int mutPolyn(PLink L1, PLink L2, PLink* L3) {
	PLink p1 = L1->next, p2 = L2->next;
	Term x;
	(*L3) = (PLink)malloc(sizeof(PNode));
	if (*L3 == NULL)
		return 0;
	(*L3)->next = NULL;
	while (p1) {
		p2 = L2->next;
		while (p2) {
			x.coef = p1->data.coef * p2->data.coef;
			x.exp = p1->data.exp + p2->data.exp;
			insertPolyn(*L3, x);
			p2 = p2->next;
		}
		p1 = p1->next;
	}
	return 1;
}

void disPolyn(PLink L)
{
	PLink p = L->next;
	while (p) {
		if (p->data.coef < 0)
			printf("%fX^%d", p->data.coef, p->data.exp);
		else
			printf("+%fX^%d", p->data.coef, p->data.exp);
		p = p->next;
	}
	printf("\n");
}

int main()
{
	return 0;
}
