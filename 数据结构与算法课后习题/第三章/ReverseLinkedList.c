#include <stdio.h>
#include <stdlib.h>

typedef struct linknode
{
	int data;
	struct linknode *next;
}LinkNode;

void reverseList(LinkNode **head);
LinkNode* InitList();
int main()
{
	LinkNode *head = InitList();
	reverseList(&head);
	while (head != NULL)
	{
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");

	return 0;
}

void reverseList(LinkNode **head)
{
	LinkNode *pre = NULL;
	LinkNode *temp = (*head)->next;

	while (*head != NULL)
	{
		(*head)->next = pre;
		pre = *head;
		*head = temp;
		if (temp != NULL)
			temp = temp->next;
	}

	*head = pre;
}

LinkNode* InitList()
{
	int n = 0;
	scanf("%d", &n);

	int temp = 0;
	LinkNode *head = NULL, *tail = NULL;
	head = tail = (LinkNode*)malloc(sizeof(LinkNode));
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		LinkNode *node = (LinkNode*)malloc(sizeof(LinkNode));
		node->data = temp;
		node->next = NULL;

		tail->next = node;
		tail = node;
	}

	LinkNode *ans = head->next;
	free(head);
	return ans;
}