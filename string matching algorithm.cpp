#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h> 
#include<Windows.h>
#include<time.h>
#include<malloc.h>

typedef char SString[1000];

int Index(SString S, SString T)
{
	int i = 0, j = 0;
	int len_S = strlen(S);
	int len_T = strlen(T);
	while (i <= len_S - len_T && j < len_T) {
		if (S[i] == T[j]) {
			i++;
			j++;
		}
		else {
			i = i - j + 1;
			j = 0;
		}
	}
	if (j >= len_T)
		return i - len_T;
	else
		return 0;
}

int main()
{
	SString S = "asasdasddsadsad";
	SString T = "sda";
	int a = Index(S, T);
	printf("%d", a);
	return 0;
}