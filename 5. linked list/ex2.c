#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char element;
typedef struct Qnode
{
	element data;
	struct Qnode* link;
}Qnode;

typedef struct
{
	Qnode *front, *rear;
}LQueueType;

LQueueType *createLinkedQueue()
{
	LQueueType *LQ;
	LQ = malloc(sizeof(LQueueType));
	LQ->front = NULL;
	LQ->rear = NULL;
	return LQ;
}

int isEmpty(LQueueType* LQ)
{
	if (LQ->front == NULL)
	{
		printf("Linked Queue is empty! ");
		return 1;
	}
	else return 0;
}

void enQueue(LQueueType *LQ, element item)
{
	Qnode *newNode = malloc(sizeof(Qnode));
	newNode->data = item;
	newNode->link = NULL;
	if (LQ->front == NULL)
	{
		LQ->front = newNode;
		LQ->rear = newNode;
	}
	else
	{
		LQ->rear->link = newNode;
		LQ->rear=newNode;
	}
}

element deQueue(LQueueType *LQ)
{
	Qnode *old = LQ->front;
	element item;
	if (isEmpty(LQ)) return 0;
	else
	{
		LQ->front = LQ->front->link;
		if (LQ->front == NULL)
			LQ->rear = NULL;
		item = old->data;
		free(old);
		return item;
	}
}

void printLQ(LQueueType *LQ)
{
	Qnode *temp = LQ->front;
	printf(" Linked Queue : [");
	while (temp)
	{
		printf("%3c", temp->data);
		temp = temp->link;
	}
	printf(" ] ");
}

void main()
{
	LQueueType *LQ = createLinkedQueue();
	element data;

	printf("\n ***** Queue ***** \n");
	printf("\n enqueue J >>"); enQueue(LQ,'J'); printLQ(LQ);
	printf("\n enqueue A >>"); enQueue(LQ, 'A'); printLQ(LQ);
	printf("\n enqueue G >>"); enQueue(LQ, 'G'); printLQ(LQ);
	printf("\n enqueue U >>"); enQueue(LQ, 'U'); printLQ(LQ);
	printf("\n enqueue E >>"); enQueue(LQ, 'E'); printLQ(LQ);

	printf("\n dequeue >>"); data = deQueue(LQ); printLQ(LQ);
	printf("\tdequeue data: %c", data);
	printf("\n dequeue >>"); data = deQueue(LQ); printLQ(LQ);
	printf("\tdequeue data: %c", data);
	printf("\n dequeue >>"); data = deQueue(LQ); printLQ(LQ);
	printf("\tdequeue data: %c", data);
	printf("\n dequeue >>"); data = deQueue(LQ); printLQ(LQ);
	printf("\tdequeue data: %c", data);
	printf("\n dequeue >>"); data = deQueue(LQ); printLQ(LQ);
	printf("\tdequeue data: %c", data);
	getchar();
}