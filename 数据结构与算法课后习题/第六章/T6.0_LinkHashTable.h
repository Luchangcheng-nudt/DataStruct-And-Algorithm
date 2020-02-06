//Programmer: Luchangcheng  2020/02/06
//Compiler: gcc version 9.2.1 20191008 (Ubuntu 9.2.1-9ubuntu2)   std=C++11  tested on Ubuntu Kylin 19.10.1
#include <iostream>
#define ERROR -1
using namespace std;

template<class T>
class LinkHashTable
{
private:
    struct Node
    {
        T data;
        Node* next;
        Node* near;
    };
    Node* head;
    int curSize;
    void ExpandTable();
    int Hash(T data);
public:
    LinkHashTable();
    ~LinkHashTable();
    void InsertNode(T data);
    void VisitTable();
    int DeleteNode(T data);
    void Find(T data);
};

template<class T>
LinkHashTable<T>::LinkHashTable()
{
    this->head = new Node;
    this->head->data = 0x7f7f7f7f;
    this->head->next = NULL;
    this->head->near = NULL;
    this->curSize = 0;
}

template<class T>
LinkHashTable<T>::~LinkHashTable()
{
}

template<class T>
void LinkHashTable<T>::InsertNode(T data)
{
    int hash = this->Hash(data);
    while (hash > this->curSize)
        this->ExpandTable();
    
    int t = 0;
    Node* ptr = this->head;
    while (t < hash)
    {
        t++;
        ptr = ptr->next;
    }

    bool isToInsert = 1;
    while (ptr->near != NULL)
    {
        if (ptr->data == data)
        {
            isToInsert = 0;
            break;
        }
        ptr = ptr->near;
    }
    isToInsert = (ptr->data != data);

    if (isToInsert == 1)
    {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;
        newNode->near = NULL;
        ptr->near = newNode;
    }
}

template<class T>
void LinkHashTable<T>::ExpandTable()
{
    Node* temp = this->head;
    while (temp->next != NULL)
        temp = temp->next;

    Node* newNode = new Node;
    newNode->data = 0x7f7f7f7f;
    newNode->next = NULL;
    newNode->near = NULL;
    temp->next = newNode;
    
    this->curSize++;
}

template<class T>
void LinkHashTable<T>::VisitTable()
{
    Node* temp = this->head;
    for (int i = 0; i <= curSize; i++)
    {
        cout << "Hash值为 " << i << " 的数据有： ";
        Node* tmp = temp;
        tmp = tmp->near;

        while (tmp != NULL)
        {
            cout << tmp->data << " ";
            tmp = tmp->near;
        }
        cout << endl;

        temp = temp->next;
    }
}

template<class T>
void LinkHashTable<T>::Find(T data)
{
    int hash = this->Hash(data);
    int t = 0;
    Node* table = this->head;
    while (t < hash)
    {
        t++;
        table = table->next;
    }

    Node* ptr = table->near;
    int y = 1;
    while (ptr != NULL && ptr->data != data)
    {
        ptr = ptr->near;
        y++;
    }

    if (ptr != NULL)
        cout << "找到数据，在Hash值为 " << hash << " 的第 " << y << " 个位置" << endl;
    else 
        cout << "查找失败，数据未在Hash表中" << endl; 
}

template<class T>
int LinkHashTable<T>::DeleteNode(T data)
{
    int hash = this->Hash(data);
    int t = 0;
    Node* table = this->head;
    while (t < hash)
    {
        t++;
        table = table->next;
    }

    Node* preNode = table;
    Node* ptr = table->near;
    int y = 1;
    while (ptr != NULL && ptr->data != data)
    {
        preNode = preNode->near;
        ptr = ptr->near;
        y++;
    }
    
    if (ptr != NULL)
    {
        Node* temp = ptr;
        preNode->near = temp->near;
        delete temp;
        return 0;
    }
    else 
        return ERROR;
}

template<class T>
int LinkHashTable<T>::Hash(T data)
{
    return (int)data % 10;
}
