//Programmer: Luchangcheng  2020/01/22
//Compiler: gcc version 9.2.1 20191008 (Ubuntu 9.2.1-9ubuntu2)  tested on Ubuntu Kylin 19.10.1
void DeleteElements(Node* head, int min, int max)
{
    if (head == NULL)
        return;

    Node* leftPre = NULL;
    while (head->data <= min)
    {
        leftPre = head;
        head = head->next;
    }
    Node* left = head;

    Node* rightPre = left;
    while (head->data < max)
    {
        rightPre = head;
        head = head->next;
    }

    leftPre->next = head;

    while (left != rightPre)
    {
        Node* temp = left;
        left = left->next;
        delete temp;
    }
    delete left;
}
