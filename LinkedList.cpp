#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void Print(Node *head)
{
    while(head != NULL)
    {
        cout << head->data << '\n';
        head = head->next;
    }
}

int GetSize(Node *head)
{
    int cnt = 0;
    while(head != NULL)
    {
        head = head->next;
        cnt++;
    }
    return cnt;
}

int FindMergeNode(Node *headA, Node *headB)
{
    int sizeA = GetSize(headA), sizeB = GetSize(headB);

    if(sizeA > sizeB)
        for(int i=0; i<sizeA-sizeB; i++)
            headA = headA->next;

    else if(sizeB > sizeA)
        for(int i=0; i<sizeB-sizeA; i++)
            headB = headB->next;

    while(headA != headB)
    {
        headA = headA->next;
        headB = headB->next;
    }
    return headA->data;
}

Node* InsertTail(Node *head, int data)
{
    Node *temp, *last;
    temp = new Node;
    last = head;
    temp->data = data;
    temp->next = NULL;
    if(head != NULL)
    {
        while(last->next != NULL)
            last = last->next;
        last->next = temp;
    }
    else
        head = temp;
    return head;
}

Node* InsertHead(Node *head,int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = head;
    return temp;
}

Node* InsertNth(Node *head, int data, int position)
{
    Node *temp = new Node, *pos = head;
    temp->data = data;

    if(position == 0)
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        while(--position)
            pos = pos->next;
        temp->next = pos->next;
        pos->next = temp;
    }
    return head;
}

Node* Delete(Node *head, int position)
{
    Node *pos=head, *temp;
    if(position == 0)
    {
        head = head->next;
        delete pos;
    }
    else
    {
        while(--position)
            pos = pos->next;
        temp = pos->next;
        delete temp;
        pos->next = pos->next->next;
    }
    return head;
}

void ReversePrint(Node *head)
{
    if(head == NULL)
        return;
    else
    {
        ReversePrint(head->next);
        cout << head->data << '\n';
        return;
    }
}

Node* Reverse(Node *head)
{
    Node *prev, *temp, *last;

    if(head->next == NULL)
        return head;

    prev = head;
    temp = prev->next;
    last = temp->next;
    head->next = NULL;

    while(last != NULL)
    {
        temp->next = prev;
        prev = temp;
        temp = last;
        last = last->next;
    }
    temp->next = prev;
    return temp;
}

int CompareLists(Node *headA, Node* headB)
{
    while(headA != NULL && headB != NULL && headA->data == headB->data)
    {
        headA = headA->next;
        headB = headB->next;
    }
    if(headA == NULL && headB == NULL)
        return 1;
    return 0;
}

Node* MergeLists(Node *headA, Node* headB)
{
    Node *headC = NULL, *temp;

    if(headA == NULL)
        return headB;
    else if(headB == NULL)
        return headA;

    if(headA->data <= headB->data)
    {
        headC = headA;
        headA = headA->next;
    }
    else
    {
        headC = headB;
        headB = headB->next;
    }
    headC->next = NULL;
    temp = headC;

    while(headA != NULL && headB != NULL)
    {
        if(headA->data <= headB->data)
        {
            temp->next = headA;
            headA = headA->next;
        }
        else
        {
            temp->next = headB;
            headB = headB->next;
        }
        temp = temp->next;
        temp->next = NULL;
    }

    if(headA != NULL)
        temp->next = headA;
    else if(headB != NULL)
        temp->next = headB;

    return headC;
}

int GetNode(Node *head,int positionFromTail)
{
    Node* temp = head;
    while(positionFromTail--)
        temp = temp->next;
    while(temp->next != NULL)
    {
        temp = temp->next;
        head = head->next;
    }
    return head->data;
}

Node* RemoveDuplicates(Node *head)
{
    Node *temp, *temp2;
    temp = head;
    while(temp != NULL)
    {
        temp2 = temp->next;
        while(temp2 != NULL && temp->data == temp2->data)
        {
            temp->next = temp2->next;
            delete temp2;
            temp2 = temp->next;
        }
        temp = temp->next;
    }
    return head;
}

bool HasCycle(Node* head)
{
    if(head == NULL)
        return 0;
    Node *temp = head;
    while(temp != NULL && temp->next != NULL)
    {
        head = head->next;
        temp = temp->next->next;
        if(temp == head)
            return 1;
    }
    return 0;
}

int main()
{
    return 0;
}
