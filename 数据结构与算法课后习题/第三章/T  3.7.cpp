//Programer: Luchangcheng  2020/01/22
//Compiler: gcc version 9.2.1 20191008 (Ubuntu 9.2.1-9ubuntu2)  C++11  tested on Ubuntu Kylin 19.10.1 

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Term
{
    double coeft;
    int power;
};
struct Node
{
    Term point;
    Node* next;
};
bool cmp(Node* a, Node* b)
{
    return a->point.power > b->point.power;
}
Node* GenLine();
int main()
{
    Node* list = GenLine();
    Node* calulator = list;

    cout << "The multi Line are:" << endl;
    while (list != NULL)
    {
        cout << list->point.coeft << " " << list->point.power << endl;
        list = list->next;
    }

    double x = 0;
    cout << "Input x: ";
    cin >> x;
    while (x != 0)
    {
        Node* temp = calulator;
        double sum = 0;
        while (temp != NULL)
        {
            sum += temp->point.coeft * pow(x, temp->point.power);
            temp = temp->next;
        }
        cout << "The answer is: " << sum << endl;
        cout << "Input x: ";
        cin >> x;
    }

    cout << "Cause you input 0, Program end" << endl;
    return 0;
}

Node* GenLine()
{
    double coeft = 0;
    int power = 0;

    vector<Node*>list;
    cin >> coeft >> power;
    Node* head = new Node;
    head->point = {coeft, power};
    head->next = NULL;
    list.push_back(head);

    while (power != 0)
    {
        cin >> coeft >> power;
        Node* node = new Node;
        node->point = {coeft, power};
        node->next = NULL;
        list.push_back(node);
    }

    sort(list.begin(), list.end(), cmp);

    int size = list.size();
    head = list[0];
    Node* ans = head;
    for (int i = 1; i < size; i++)
    {
        ans->next = list[i];
        ans = ans->next;
    }
    ans->next = NULL;

    return head;
}
