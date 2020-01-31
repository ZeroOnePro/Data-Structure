#pragma warning(disable: 4996) 
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	char ch = 'c';
	char *chptr = &ch;

	int i = 20;
	int *intptr = &i;

	char *ptr = "I am a string";

	printf("\n [%c], [%d], [%c], [%d], [%c], [%s]\n",*chptr,*intptr,*ptr,ptr+5,*(ptr+5),ptr);

	getchar();

	return 0;
}