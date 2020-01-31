#pragma warning(disable: 4996)
#include <stdio.h>

long long fact(int n);

int main()
{
	int n;
	long long result;
	printf("학번 201520908 이름 유성민\n\n");

	printf("Input 'N'\n> ");
	scanf("%d", &n);

	result = fact(n);

	printf("%lld\n", result);

	getchar();
	getchar();
	return 0;
}

long long fact(int n)
{
	long long value;

	if (n <= 1)
	{
		printf("fact(1) called! \n");
		printf("fact(1) returned!!\n");
		return 1;
	}
	else
	{
		printf("fact(%d) called!! \n", n);
		value = n * fact(n - 1);
		printf("fact(%d) returned value : %lld !!\n", n, value);
		return value;
	}
}