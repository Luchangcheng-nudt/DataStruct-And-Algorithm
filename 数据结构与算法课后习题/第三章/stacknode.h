#ifndef _NODE_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

struct stacknode
{
	struct stacknode *next; /*next为指向下一结点的指针*/
	ElementType data;
};
typedef struct stacknode StackNode;

void Push(StackNode**top, ElementType x);
ElementType Pop(StackNode** top);
ElementType Top(StackNode* top);

void Push(StackNode**top, ElementType x)
{
	StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
	newNode->data = x;
	newNode->next = *top;
	*top = newNode;
}

ElementType Pop(StackNode** top)
{
	ElementType ans = (*top)->data;
	StackNode* temp = *top;
	*top = (*top)->next;
	free(temp);
	return ans;
}

ElementType Top(StackNode* top)
{
	if (top != NULL)
		return top->data;
	return -1;
}

#endif