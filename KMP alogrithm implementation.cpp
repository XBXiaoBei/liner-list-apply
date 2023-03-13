#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h> 
#include<Windows.h>
#include<time.h>
#include<malloc.h>
#include<cstring>
#include<iostream>

typedef char SString[100];

int creatindex(int index[], SString str);

int compSString(SString L, SString S, int len, int index[], int len_Comparing);

int main()
{
	SString Str_Compared;
	SString Str_Comparing;
	int length_Compared, length_Comparing;
	int index[100] = { 0 };
	printf("请输入Str_Compared:");
	scanf("%s", Str_Compared);
	getchar();
	printf("请输入Str_Comparing:");
	scanf("%s", Str_Comparing);
	getchar();
	length_Compared = strlen(Str_Compared);
	length_Comparing = strlen(Str_Comparing);
	//printf("%d, %d", length_Compared, length_Comparing);
	creatindex(index, Str_Compared);
	/*for (int i = 0; i < 10; i++)
		printf("%d ", index[i]);*/
	compSString(Str_Compared, Str_Comparing, length_Compared - length_Comparing, index, length_Comparing);
	return 0;
}

int creatindex(int index[], SString str)
{
	index[0] = 0;
	int i = 1, j = 0;
	while (str[i]) {
		if (str[i] == str[j]) {
			index[i] = index[i - 1] + 1;
			i++;
			j++;
		}
		else if (j == 0) {
			index[i] = 0;
			i++;
		}
		else {
			j = index[j - 1];
		}
	}
	return 0;
}

int	compSString(SString L, SString S, int len, int index[], int len_Comparing)
{
	int i = 0, j = 0;
	/*while (S[i])
		printf("%c", S[i++]);*/
	while (i - j <= len) {
		if (j == len_Comparing) {
			printf("有\n");
			printf("位置是:%d到%d\n", i - j + 1, i - j + len_Comparing);
			return 1;
		}
		if (L[i] == S[j]) {
			i++;
			j++;
		}
		else {
			i++;
			if (j == 0)
				j = 0;
			else
				j = index[j - 1];
		}
	}
	printf("没有\n");
	return 0;
}