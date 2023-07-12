#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    node *next;
};

node *createNode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}
void addFirst(node *l, int data)
{
    node *temp = createNode(data);
    temp->next = l;
    l = temp;
}
void addLast(node *l, int data)
{
    node *temp = createNode(data);
    node *next = l;
    while (next->next != NULL)
    {
        next = next->next;
    }
    next->next = temp;
}
node *findKey(node *l, int data)
{
    node *temp = l;
    while (temp->next != NULL)
    {
        if (temp->data == data)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}
void addAt(node *l, int data, int offset)
{
}

int main()
{
}