#include <stdio.h>

int main()
{
	char *ptrArray[2];
	char **ptrptr;
	int i;
	ptrArray[0] = "Korea";
	ptrArray[1] = "Suwon";
	ptrptr = ptrArray;

	printf("%u\n", ptrArray);
	printf("%u\n", ptrArray[0]);
	printf("%c\n", *ptrArray[0]);
	printf("%c\n", *(ptrArray[0]+1));
	printf("%s\n", *ptrArray);

	printf("%u\n", ptrArray+1);
	printf("%u\n", ptrArray[1]);
	printf("%c\n", *ptrArray[1]);
	printf("%c\n", *(ptrArray[1] + 1));
	printf("%s\n", *(ptrArray+1));

	printf("%u\n", &ptrptr);
	printf("%u\n", ptrptr);
	printf("%u\n", *ptrptr);
	printf("%c\n", *(*ptrptr+0));
	printf("%c\n", *(*ptrptr + 1));
	printf("%s\n", *ptrptr);
	getchar();
}