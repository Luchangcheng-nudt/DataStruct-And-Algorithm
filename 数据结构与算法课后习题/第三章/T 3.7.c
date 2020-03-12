#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct term Term;
typedef struct node Node;
struct term
{
    double coeft;
    int power;
};
struct node
{
    Term point;
    Node* next;
};
Node* GenerateLine();
void MergeSort(Node* data[], int left, int right);
void Merge(Node* data[], int left, int mid, int right);
void ShowLinkedList(Node* LinkedList);

int main()
{
    Node* LinkedList = GenerateLine();
    ShowLinkedList(LinkedList);
    Node* temp = LinkedList;

    int x = 0;
    printf("Input x (end 0 0): ");
    while (scanf("%d", &x) != EOF && x != 0)
    {
        double ans = 0.0;
        while (temp != NULL)
        {
            ans += temp->point.coeft * pow(x, temp->point.power);
            temp = temp->next;
        }
        printf("The result is: %.2lf\nInput x (end 0 0): ", ans);
        temp = LinkedList;
    }

    return 0;
}

Node* GenerateLine()
{
    Node* vector[101] = {0};
    int m = 0;
    double coeft = 0.0;
    int power = 0;

    printf("Input mutiple line, end 0 0: ");
    while (scanf("%lf%d", &coeft, &power) != EOF && (coeft != 0 || power != 0))
    {
        Node* temp = (Node*)malloc(sizeof(Node));
        temp->point.coeft = coeft;
        temp->point.power = power;
        temp->next = NULL;

        vector[m++] = temp;
    }

    MergeSort(vector, 0, m);
    int i = 0;
    for (i; i < m - 1; i++)
        vector[i]->next = vector[i + 1];
    vector[i]->next = NULL;
    return vector[0];
    
}

void MergeSort(Node* data[], int left, int right)
{
    if (left + 1 < right)
    {
        int mid = (left + right) >> 1;
        MergeSort(data, left, mid);
        MergeSort(data, mid, right);
        Merge(data, left, mid, right);
    }
}

void Merge(Node* data[], int left, int mid, int right)
{
    Node* temp[101] = {0};
    int i = left;
    int j = mid;
    int m = 0;

    while (i < mid && j < right)
        temp[m++] = data[i]->point.power < data[j]->point.power ?  data[j++] : data[i++];

    while (i < mid)
        temp[m++] = data[i++];
    while (j < right)
        temp[m++] = data[j++];
    
    for (i = 0; i < m; i++)
        data[left++] = temp[i];
}

void ShowLinkedList(Node* LinkedList)
{
    printf("The mutiple line is: ");
    while (LinkedList != NULL)
    {
        printf("%.2lf  %d  ", LinkedList->point.coeft, LinkedList->point.power);
        LinkedList = LinkedList->next;
    }
    printf("\n");
}