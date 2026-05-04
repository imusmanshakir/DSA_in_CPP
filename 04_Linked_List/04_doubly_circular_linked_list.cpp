#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

void insertAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (!head)
    {
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
        return;
    }
    Node *oldHead = head;
    Node *tail = oldHead->prev;
    newNode->next = oldHead;
    newNode->prev = tail;
    tail->next = newNode;
    oldHead->prev = newNode;
};

void insertAtTail(Node *head, int val) {};

void print(Node *head)
{
    if (!head)
    {
        cout << "LIST is empty\n";
        return;
    }
    // priting forward
    Node *forward = head;
    cout << "Forward:->";
    do
    {
        cout << forward->data << " -> ";
        forward = forward->next;
    } while (forward != head);
    cout << " Back to head <-\n";
    // printing backward
    Node *tail = head->prev;
    cout << "Backward:";
    cout << " -> Back to tail ";
    do
    {
        cout << tail->data << " <- ";
        tail = tail->prev;
    } while (tail != head->prev);

    cout << "\n";
}

int main()
{
    Node *head = nullptr;
    cout << "Inserting at head\n";
    insertAtHead(head, 10);
    insertAtHead(head, 20);
    insertAtHead(head, 30);
    print(head);

    return 0;
}