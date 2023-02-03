#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"

int NextPosIdx(int pos)
{
    if (pos == QUE_LEN - 1)
    {
        return 0;
    }
    else
    {
        return pos + 1;
    }
}

void QueueInit(Queue *pq)
{
    pq->front = 0;
    pq->rear = 0;
}

int QIsEmpty(Queue *pq)
{
    if (pq->front == pq->rear)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void Enqueue(Queue *pq, Data data)
{
    if (pq->front == NextPosIdx(pq->rear))
    {
        printf("Queue is full.\n");
        exit(-1);
    }
    else
    {
        pq->rear = NextPosIdx(pq->rear);
        pq->queArr[pq->rear] = data;
    }
}

Data Dequeue(Queue *pq)
{
    if (QIsEmpty(pq))
    {
        printf("ERROR: Queue is empty\n");
        exit(-1);
    }
    pq->front = NextPosIdx(pq->front);
    int data;
    data = pq->queArr[pq->front];
    return data;
}

Data QPeek(Queue *pq)
{
    if (QIsEmpty(pq))
    {
        printf("ERROR: Queue is Empty\n");
        exit(-1);
    }
    return pq->queArr[pq->front];
}