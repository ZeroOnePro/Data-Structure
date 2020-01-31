#pragma warning(disable: 4996)
#include <stdio.h>

void hanoi(int n,char start, char work, char target);

int main()
{
	int n;
	printf("학번 201520908 이름 유성민\n\n");
	printf("Number of disk. > ");
	scanf(" %d", &n);
	hanoi(n, 'A', 'B', 'C');

	getchar();
	getchar();
	return 0;
}

void hanoi(int n, char start, char work, char target)
{
	if (n == 1)
	{
		printf("%c 에서 %c로 %d번째 원판이 옮겨졌음\n", start, target, n);
	}

	else
	{
		hanoi(n - 1, start, target, work);
		printf("%c 에서 %c로 %d번째 원판이 옮겨졌음\n", start, target, n);
		hanoi(n - 1, work, start, target);
	}
}