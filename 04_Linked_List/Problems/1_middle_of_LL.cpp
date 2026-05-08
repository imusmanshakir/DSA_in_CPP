#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

// Works for BOTH singly and doubly linear lists
void insertAtTail(Node *&head, int val)
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

// Print the list
void printList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Find middle using slow & fast pointers
Node *findMiddle(Node *head)
{
    if (head == nullptr)
        return nullptr;

    Node *slow = head;
    Node *fast = head;

    // fast moves two steps, slow moves one step
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    // When fast reaches the end, slow is at the middle
    return slow;
}

int main()
{
    Node *head = nullptr;

    // Build a test list: 10 -> 20 -> 30 -> 40 -> 50 -> NULL
    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);
    insertAtTail(head, 50);

    cout << "Original list: ";
    printList(head); // 10 -> 20 -> 30 -> 40 -> 50 -> NULL

    Node *mid = findMiddle(head);
    if (mid)
        cout << "Middle node data: " << mid->data << endl; // 30
    else
        cout << "List is empty.\n";

    // Even length example
    insertAtTail(head, 60); // now: 10->20->30->40->50->60->NULL
    cout << "\nAfter adding 60: ";
    printList(head); // 10 -> 20 -> 30 -> 40 -> 50 -> 60 -> NULL

    mid = findMiddle(head);
    if (mid)
        cout << "Middle node data (even length): " << mid->data << endl; // 40 (first middle)
    else
        cout << "List is empty.\n";

    return 0;
}