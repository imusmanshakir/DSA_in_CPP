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
        newNode->next = head;
        return;
    }

    Node *temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
}

void printList(Node *head)
{

    if (head == nullptr)
        return;

    Node *temp = head;

    do
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "NULL\n";
}

void splitList(Node *head, Node *&head1, Node *&head2)
{

    // Empty list
    if (head == nullptr)
        return;

    Node *slow = head;
    Node *fast = head;

    // Find middle using slow-fast pointers
    while (fast->next != head &&
           fast->next->next != head)
    {

        slow = slow->next;
        fast = fast->next->next;
    }

    // For even number of nodes
    if (fast->next->next == head)
    {
        fast = fast->next;
    }

    // First half starts from head
    head1 = head;

    // Second half starts after slow
    head2 = slow->next;

    // Make first circular
    slow->next = head1;

    // Make second circular
    fast->next = head2;
}

int main()
{

    Node *head = nullptr;

    insertAtEnd(head, 10);
    insertAtEnd(head, 4);
    insertAtEnd(head, 9);
    insertAtEnd(head, 7);

    cout << "Original Circular List:\n";
    printList(head);

    Node *head1 = nullptr;
    Node *head2 = nullptr;

    splitList(head, head1, head2);

    cout << "First Half:\n";
    printList(head1);

    cout << "Second Half:\n";
    printList(head2);

    return 0;
}