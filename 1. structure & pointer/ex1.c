#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
int main()
{
	int i;
	char string1[20] = "Dreams come true!";
	char string2[20];
	char *ptr1, *ptr2;

	printf("%u\n", string1);
	ptr1 = string1;
	printf("%u\n", ptr1);
	printf("%s\n", string1);
	printf("%s\n", ptr1);
	printf("%s\n", ptr1 + 7);
	ptr2 = string1 + 7;
	for (i = 0; i < 20; i++)
	{
		string2[i] = *(ptr1 + i);
	}
	for (i = 16; i >= 0; i--)
	{
		putchar(*(ptr1 + i));
	}
	printf("\n");
	printf("%s\n", string2);
	*ptr1 = 'P';
	*(ptr1 + 1) = 'e';
	printf("%s\n", ptr1);
	getchar();
}