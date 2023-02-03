#include <stdio.h>
#include "ListBaseQueue.h"
#include "ListBaseQueue.c"

int main(void)
{
	// Queue의 생성 및 초기화 ///////
	Queue q;
	QueueInit(&q);

	// 데이터 대입 ///////
	Enqueue(&q, 1);
	Enqueue(&q, 2);
	Enqueue(&q, 3);
	Enqueue(&q, 4);
	Enqueue(&q, 5);

	// 출력 ///////
	while (!QIsEmpty(&q))
		printf("%d ", Dequeue(&q));

	return 0;
}