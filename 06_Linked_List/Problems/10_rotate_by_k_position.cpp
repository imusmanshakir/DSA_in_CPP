#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

void insertAtEnd(Node *&head, int val)
{

    Node *newNode = new Node(val);

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node *temp = head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void printList(Node *head)
{

    while (head != nullptr)
    {
        cout << head->data << " -> ";
        head = head->next;
    }

    cout << "NULL\n";
}

Node *rotateByK(Node *head, int k)
{

    // Empty or single node
    if (head == nullptr || head->next == nullptr)
        return head;

    // Find length and tail
    Node *tail = head;
    int length = 1;

    while (tail->next != nullptr)
    {
        tail = tail->next;
        length++;
    }

    // If k > length
    k = k % length;

    // No rotation needed
    if (k == 0)
        return head;

    // Make circular
    tail->next = head;

    // Find new tail
    int steps = length - k;

    Node *newTail = head;

    for (int i = 1; i < steps; i++)
    {
        newTail = newTail->next;
    }

    // New head
    Node *newHead = newTail->next;

    // Break circle
    newTail->next = nullptr;

    return newHead;
}

int main()
{

    Node *head = nullptr;

    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);

    cout << "Original List:\n";
    printList(head);

    int k = 2;

    head = rotateByK(head, k);

    cout << "After Rotation:\n";
    printList(head);

    return 0;
}

// For step by step guide:
// https://www.kimi.com/share/19e1b0f8-c2b2-8479-8000-000034d058a8