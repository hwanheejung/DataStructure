#include <stdio.h>
#include <stdlib.h>
#include "ArrayBaseStack.h"

void StackInit(Stack *pstack)
{
    pstack->topIndex = -1;
}

int SIsEmpty(Stack *pstack)
{
    if (pstack->topIndex == -1)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void SPush(Stack *pstack, Data data)
{
    if ((pstack->topIndex) >= STACK_LEN)
    {
        printf("Stack is full\n");
    }
    pstack->topIndex += 1;
    pstack->stackArr[pstack->topIndex] = data;
}

Data SPop(Stack *pstack)
{
    if (SIsEmpty(pstack))
    {
        printf("ERROR\n");
        exit(-1);
        /* return은 허용가능한 반환.프로그램 전체에 큰 영향이 없음.
            exit는 허용 불가. 이 함수가 호출됨으로 인해 프로그램에 영향이 감. 프로그램 버그.
        */
    }
    int data;
    data = pstack->stackArr[pstack->topIndex];
    pstack->topIndex -= 1;
    return data;
}

Data SPeek(Stack *pstack)
{
    if (SIsEmpty(pstack))
    {
        printf("ERROR\n");
        exit(-1);
    }
    return pstack->stackArr[pstack->topIndex];
}