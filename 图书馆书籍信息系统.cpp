#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h> 
#include<Windows.h>
#include<time.h>
#include<malloc.h>

typedef struct
{
	int book_num;
	char name[100];
	double price;
}ElemType;

typedef struct
{
	ElemType* data;
	int maxsize;
	int length;
}SqList;

int initSqList(SqList* L, int maxsize)
{
	L->data = (ElemType*)malloc(maxsize * sizeof(ElemType));
	if (L->data == NULL) {
		printf("空间申请失败！\n");
		return 0;
	}
	L->maxsize = maxsize;
	L->length = 0;
	return 1;
}

int insertSqList(SqList* L, int pos, ElemType Elem_insert)
{
	if (pos < 1 || pos > L->length + 1) {
		printf("插入位置异常\n");
		return 0;
	}
	if (L->length >= L->maxsize) {
		printf("容量不够\n");
		return 0;
	}
	for (int K = L->length - 1; K >= pos - 1; K--) {
		L->data[K + 1] = L->data[K];
	}
	L->data[pos - 1] = Elem_insert;
	L->length++;
	return 1;
}

int deleteSqList(SqList* L, int pos)
{
	if (L->length == 0) {
		printf("没有数据，不能删除！\n");
		return 0;
	}
	if (pos <= 0 || pos > L->length) {
		printf("位置异常，不能删除！\n");
		return 0;
	}
	for (int k = pos; k < L->length; k++) {
		L->data[k - 1] = L->data[k];
	}
	L->length--;
	return 1;
}

int locationSqList(SqList L, char name[100])
{
	if (L.length == 0) {
		printf("没有数据！\n");
		return 0;
	}
	for (int i = 0; i < L.length; i++) {
		if (strcmp(L.data[i].name, name) == 0) {
			return i + 1;
		}
	}
	return -1;
}

int dispSqList(SqList L)
{
	if (L.length == 0) {
		printf("没有数据！\n");
		return 0;
	}
	for (int i = 0; i < L.length; i++) {
		printf("%d %s %f\n", L.data[i].book_num, L.data[i].name, L.data[i].price);
	}
	return 1;
}

int creatSqList(SqList* L, int i)
{
	scanf("%d %s %lf", &L->data[i].book_num, L->data[i].name, &L->data[i].price);
	getchar();
	L->length++;
	return 1;
}

int menu()
{
	int step;
	//system("cls");
	printf("************************\n");
	printf("欢迎进入图书管理系统\n");
	printf("\t1.初始化图书信息\n");
	printf("\t2.输入图书信息\n");
	printf("\t3.输出图书信息\n");
	printf("\t4.插入图书信息\n");
	printf("\t5.删除图书信息\n");
	printf("\t6.查找图书信息\n");
	printf("\t7.更新图书信息\n");
	printf("\t8.退出管理系统\n");
	printf("请输入你的操作：");
	scanf("%d", &step);
	printf("************************\n");
	return step;
}

int main()
{
	SqList L;
	int maxsize;
	int judge;
	int pos;
	char yn;
	char name[100];
	int judge_temp = 0;
	while (1) {
		judge = menu();
		switch (judge)
		{
		case 1:
			printf("开始初始化操作：\n");
			printf("请输入线性表的长度：");
			scanf("%d", &maxsize);
			if (initSqList(&L, maxsize))
				printf("操作成功\n");
			else
				printf("操作失败\n");
			break;
		case 2:
			printf("开始录入操作：\n");

			for (int i = 0; i < L.maxsize; i++)
			{
				printf("请输入需要录入图书的编号、书名、价格，用空格隔开：\n");
				judge_temp = creatSqList(&L, i);
				if (i == L.maxsize - 1) {
					printf("线性表已满\n");
					break;
				}
				printf("是否继续y/n\n");
				scanf("%c", &yn);
				if (yn == 'y')
					continue;
				else
					break;
			}
			if (judge_temp)
				printf("操作成功\n");
			else
				printf("操作失败\n");
			break;
		case 3:
			printf("开始输出操作：\n");
			if (dispSqList(L))
				printf("操作成功\n");
			else
				printf("操作失败\n");
			break;
		case 4:
			printf("开始插入操作：\n");
			printf("请输入插入的位置：");
			ElemType Elem_insert;
			scanf("%d", &pos);
			getchar();
			printf("请输入需要插入的图书的编号、书名、价格，用空格隔开：\n");
			scanf("%d %s %f", &Elem_insert.book_num, Elem_insert.name, &Elem_insert.price);
			getchar();
			if (insertSqList(&L, pos, Elem_insert))
				printf("操作成功\n");
			else
				printf("操作失败\n");
			break;
		case 5:
			printf("开始删除操作：\n");
			printf("请输入你要删除的书的名称：");
			scanf("%s", name);
			getchar();
			pos = locationSqList(L, name);
			if (deleteSqList(&L, pos))
				printf("操作成功\n");
			else
				printf("操作失败\n");
			break;
		case 6:
			printf("开始查找操作：\n");
			printf("请输入你要查找的书的名称：");
			scanf("%s", name);
			getchar();
			pos = locationSqList(L, name);
			if (pos == -1) {
				printf("没有找到该书\n");
				break;
			}
			printf("图书的信息:书号:%d 书名:%s 价格:%f\n", L.data[pos - 1].book_num, L.data[pos - 1].name, L.data[pos - 1].price);
			break;
		case 7:
			printf("开始修改操作：\n");
			printf("请输入你要修改的书的名称：");
			scanf("%s", name);
			pos = locationSqList(L, name);
			if (pos == -1) {
				printf("没有找到该书\n");
				break;
			}
			printf("请输入修改后的内容，编号、书名、价格，用空格隔开：");
			scanf("%d %s %lf", &L.data[pos - 1].book_num, L.data[pos - 1].name, &L.data[pos - 1].price);
			getchar();
			break;
		case 8:
			exit(1);
			break;
		default:
			break;
		}
	}

}
