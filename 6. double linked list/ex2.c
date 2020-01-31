#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include<stdio.h>
#include<malloc.h>
#include <Windows.h>

#define MAX_SIZE 100
#define MALLOC(p,s) (p) = (nodePointer)malloc((s));

typedef struct node *nodePointer;
typedef struct node
{
	int data;
	nodePointer link;
}node;

int main()
{
	bool out[MAX_SIZE];
	nodePointer seq[MAX_SIZE];
	nodePointer x, y, top;
	int i, j, n;

	printf("Enter the number of polygons (<=%d) ", MAX_SIZE);
	scanf("  %d", &n);

	for (i = 0; i < n; i++)
	{
		out[i] = true;
		seq[i] = NULL;
	}

	while (1)
	{
		printf("Enter a pair of numbers (-1 -1 to quit): ");
		scanf("  %d %d", &i, &j);

		if (i < 0 || j < 0) break;

		MALLOC(x, sizeof(x));
		x->data = j; x->link = seq[i]; seq[i] = x;

		MALLOC(x, sizeof(x));
		x->data = i; x->link = seq[j]; seq[j] = x;
	}

	for (i = 0; i < n; i++)
	{
		if (out[i])
		{
			printf("\n New class : %5d", i);
			out[i] = false;
			x = seq[i];
			top = NULL;

			for (;;)
			{
				while (x)
				{
					j = x->data;
					if (out[j] == true)
					{
						printf("%5d", j);
						out[j] = false;

						y = x->link;
						x->link = top;
						top = x;
						x = y;
					}
					else
					{
						x = x->link;
					}
				}
				if (!top) break;
				x = seq[top->data];
				top = top->link;
			}
		}
	}
	getchar();
	getchar();
	getchar();
	system("pause");
	return 0;
}