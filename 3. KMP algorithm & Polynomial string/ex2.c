#include <stdio.h>
#include <string.h>

int failure[100] = { 0, };
void fail(char *pat);
int pmatch(char *string, char*pat);

void main()
{
	char string[] = "Ajou university is the best in the world.";
	char pat[] = "abc";

	fail(pat);
	int matched_count = pmatch(string, pat);

	if (matched_count == -1)
	{
		printf("No pattern found");
	}
	else
	{
		printf("Index of the first pattern found : %d", matched_count);
	}

	getchar();
}

void fail(char *pat)
{
	int i, j;
	int n = strlen(pat);
	failure[0] = -1;

	for (j = 1; j < n; j++)
	{
		i = failure[j - 1];
		if(pat[j] != pat[i + 1] && i >= 0) i = failure[i]; // while() -> if() 노 상관 // f(18)=8 이면 f(8) = 그 값 참고 해서 밑의 if문에 이용됨
		if (pat[j] != pat[i + 1]) failure[j] = i + 1; // f(8)의 값 pat[19]와 pat[8] 을 비교해서 pat[8] =-1이면 앞에 볼 필요없고, pat[8]=x라면 패턴과 문자열의 0 ~ x+1 과 19-x ~ 19 의 패턴매칭 다시시작 
		else failure[j] = -1;
	}
}

int pmatch(char *string, char*pat)
{
	int i = 0;
	int j = 0;
	int lens = strlen(string);
	int lenp = strlen(pat);

	while (i < lens && j < lenp)
	{
		if (string[i] == pat[j]) { i++; j++;}
		else if (j == 0) i++; // string[i] != pat[j] 위 if문을 들어가지 않고 string 이동
		else j = failure[j - 1] + 1; // string[i] == pat[j] 일때 실패함수값 +1 = 매치된 값
	}
	return (j == lenp ? i - lenp : -1);
}