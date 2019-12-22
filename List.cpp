//Program by Luchangcheng 2019/12/1
//Compiler: clang version 9.0.0 (tags/RELEASE_900/final) tested on VScode
#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *createlist(int n);
node *insertElem(node* list, int data, int index);
node *deleteElem(node* list, int index);

int main()
{
    int n = 6;
    node *list = createlist(n);
    list = insertElem(list, 99, 5);
    list = deleteElem(list, 6);
    while(list != NULL)
    {
        cout << list->data << " ";
        node *temp = list;
        list = list->next;
        delete temp;
    }


    return 0;
}

Node* createList(int n)
{
    if (!n)
        return NULL;
    Node* head = NULL;
    Node* tail = NULL;
    head = tail = new Node;
    
    int temp = 0;
    cin >> temp;
    head->data = temp;
    head->next = NULL;
    for (int i = 1; i < n; i++)
    {
        cin >> temp;
        Node* tmp = new Node;
        tmp->data = temp;
        tail->next = tmp;
        tail = tmp;
    }
    tail->next = NULL;
    return head;
}
node *insertElem(node* list, int data, int index)
{
    node *begin = list;
    if (index <= -1)
    {
        node *point = new node;
        point->data = data;
        point->next = list;
        return point;
    }
    int t = 0;
    while (list->next != NULL && t < index)
    {
        list = list->next;
        t++;
    }

    node *point = new node;
    point->data = data;
    point->next = list->next;
    list->next = point;
    return begin;
}
node *deleteElem(node* list, int index)
{
    node *begin = list;
    if (index < 0)
        return list;
    else if (index == 0)
    {
        node *tmp = list;
        list = list->next;
        delete tmp;
        return list;
    }
    else
    {
        int t = 0;
        node *prenode = NULL;
        while (list != NULL && t < index)
        {
            prenode = list;
            list = list->next;
            t++;
        }
        if (list->next == NULL)
        {
            delete list;
            prenode->next = NULL;
        }
        else
        {
            prenode->next = list->next;
            delete list;
        }
    }
    return begin;
}
