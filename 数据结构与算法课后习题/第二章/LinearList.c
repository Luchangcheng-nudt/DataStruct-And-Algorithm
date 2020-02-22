#include <stdio.h>
#include <stdlib.h>

enum Boolean {False, True};
typedef enum Boolean Bool;
typedef struct linearlist LinearList;
typedef int ElementType;
struct linearlist
{
    ElementType* data;
    int MaxSize;
    int Last;
};
void InitList(LinearList* list, int size);
void FreeList(LinearList* list);
Bool IsListEmpty(LinearList* list);
Bool IsListFull(LinearList* list);
int ListLength(LinearList* list);
ElementType GetElem(LinearList* list, int i);
int localeElem(LinearList* list, ElementType x);
Bool InsertElem(LinearList* list, ElementType x, int i);
Bool DeleteElem(LinearList* list, int i);
void Solution(LinearList* Group, int n, int s, int m);
void swap(int* a, int* b);

int main()
{
    LinearList* list = (LinearList*)malloc(sizeof(LinearList));
    InitList(list, 6);
    for (int i = 0; i < 6; i++)
        InsertElem(list, i + 1, i);
    Solution(list, 6, 2, 3);
    for (int i = 0; i < 6; i++)
        printf("%d ", list->data[i]);
    printf("\r\n");
    return 0;
}

void InitList(LinearList* list, int size)
{
    if (size > 0)
    {
        list->data = (ElementType*)malloc(sizeof(ElementType) * size);
        list->MaxSize = size;
        list->Last = 0;
    }
}

void FreeList(LinearList* list)
{
    free(list->data);
    list->data = NULL;
}

Bool IsListEmpty(LinearList* list)
{
    return list->Last == 0 ? True : False;
}

Bool IsListFull(LinearList* list)
{
    return list->Last == list->MaxSize ? True : False;
}

int ListLength(LinearList* list)
{
    return list->Last;
}

ElementType GetElem(LinearList* list, int i)
{
    if (0 <= i && i < list->MaxSize)
        return list->data[i];
    else 
        return -1;
}

int localeElem(LinearList* list, ElementType x)
{
    for (int i = 0; i < list->Last; i++)
    {
        if (x == list->data[i])
            return i;
    }
    return -1;
}

Bool InsertElem(LinearList* list, ElementType x, int i)
{
    if (0 <= i && i <= list->Last && list->Last != list->MaxSize)
    {
        for (int j = list->Last; j > i; j--)
            list->data[j] = list->data[j-1];
        list->data[i] = x;
        list->Last++;
        return True;
    }
    return False;
}

Bool DeleteElem(LinearList* list, int i)
{
    if (0 <= i && i < list->Last)
    {
        for (int j = i; j < list->Last - 1; j++)
            list->data[j] = list->data[j+1];
        list->Last--;
        return True;
    }
    return False;
}

void Solution(LinearList* Group, int n, int s, int m)
{
    int i = n;

    while (i > 0)
    {
        s = (s + m - 1) % i;
        if (s == 0)
            s = i;
        int node = GetElem(Group, s - 1);
        DeleteElem(Group, s - 1);
        InsertElem(Group, node, n - 1);
        i--;
    }
}

void swap(int* a, int* b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}
