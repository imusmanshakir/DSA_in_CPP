#include <iostream>
using namespace std;

struct Node
{
    Node *next;
    int data;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};
void insertAtTail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (!head)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
};

void reverse(Node *&head)
{
    Node *prev = nullptr;
    Node *curr = head;
    while (curr)
    {
        Node *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    head = prev;
};

void print(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main()
{
    Node *head = nullptr;
    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);
    insertAtTail(head, 50);
    print(head);
    cout << "Reversing...\n";
    reverse(head);
    print(head);

    return 0;
}