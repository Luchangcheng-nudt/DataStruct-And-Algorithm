void Josephus(Node* list, int n, int s, int m)
{
    Node* tail = list;
    while (tail->next != NULL)
        tail = tail->next;
    tail->next = list;

    int t = 1;
    while (t < s)
    {
        list = list->next;
        t++;
    }
    
    int cnt = 0;
    Node* preNode = list;
    while (cnt < n)
    {
        int index = 1;
        while (index < m)
        {
            preNode = list;
            list = list->next;
            index++;
        }
        Node* temp = list;
        preNode->next = list->next;
        list = list->next;
        cout << temp->data << " ";
        delete temp;
        cnt++;
    }
}
