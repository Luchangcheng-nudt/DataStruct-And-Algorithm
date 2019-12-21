//Programer: Luchangcheng    2019/12/21
//Compiler: gcc version 7.4.0 (Ubuntu 7.4.0-1ubuntu1~18.04.1)   tested on Ubuntu 18.04.3 LTS
/*
struct Node
{
  int data;
  struct Node* next;
 };
 */
void Append(Node* list, Node* p)
{
    Node* tList = list;
    while (tList->next != NULL)
        tList = tList->next;
    while (p != NULL)
    {
        Node* temp = new Node;
        temp->data = p->data;
        temp->next = p->next;
        tList->next = temp;
        tList = temp;
        p = p->next;
    }
}
