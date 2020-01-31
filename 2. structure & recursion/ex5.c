#pragma warning(disable: 4996)
#include <stdio.h>
#include<time.h>
#define MAX_LENGTH (int)(61)

unsigned long long recursive_fibo(unsigned int n);
unsigned long long iterative_fibo(unsigned int n);

int main()
{
	unsigned int length;
	double begin, end;
	double t1, t2;
	unsigned long long val1, val2;
	printf("학번 201520908 이름 유성민\n\n");

	for (length = 1; length <= MAX_LENGTH; length += 5)
	{
		begin = clock();
		val1= recursive_fibo(length-1);
		end = clock();
		t1 = (end - begin) / CLOCKS_PER_SEC;

		begin = clock();
		val2 = iterative_fibo(length);
		end = clock();
		t2 = (end - begin) / CLOCKS_PER_SEC;

		printf("[Length: %3d] Reculsive : %.3lf sec, value = %lld, Iterative : %.3lf sec, value = %lld\n", length, t1, val1,t2,val2);
	}
	
	getchar();
	getchar();
	return 0;
}

unsigned long long recursive_fibo(unsigned int n)
{
	if (n == 0) return 0;
	else if (n == 1) return 1;
	else return recursive_fibo(n - 2) + recursive_fibo(n - 1);

}

unsigned long long iterative_fibo(unsigned int n)
{
	unsigned long long previous = 0;
	unsigned long long current = 1;
	unsigned long long next = 1;
	unsigned long long fibo[MAX_LENGTH];
	unsigned long long result=0;
	fibo[0] = previous;
	fibo[1] = current;
	fibo[2] = next;
	for (int i = 3; i < n; i++)
	{
		fibo[i] = fibo[i - 2] + fibo[i - 1];
		result = fibo[i];
	}
	return result;
}
