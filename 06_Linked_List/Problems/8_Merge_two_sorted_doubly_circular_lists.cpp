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

// Insert at end
void insertAtEnd(Node *&head, int val)
{

    Node *newNode = new Node(val);

    // Empty list
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

// Print linked list
void printList(Node *head)
{

    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

// Merge two sorted linked lists
Node *merge(Node *head1, Node *head2)
{

    // If one list is empty
    if (head1 == nullptr)
        return head2;
    if (head2 == nullptr)
        return head1;

    Node *head = nullptr;
    Node *tail = nullptr;

    // Merge while both lists exist
    while (head1 != nullptr && head2 != nullptr)
    {

        Node *temp = nullptr;

        if (head1->data <= head2->data)
        {
            temp = head1;
            head1 = head1->next;
        }
        else
        {
            temp = head2;
            head2 = head2->next;
        }

        // First node
        if (head == nullptr)
        {
            head = tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    // Remaining nodes
    if (head1 != nullptr)
    {
        tail->next = head1;
    }

    if (head2 != nullptr)
    {
        tail->next = head2;
    }

    return head;
}

int main()
{

    Node *head1 = nullptr;
    Node *head2 = nullptr;

    // First sorted list
    insertAtEnd(head1, 1);
    insertAtEnd(head1, 3);
    insertAtEnd(head1, 5);

    // Second sorted list
    insertAtEnd(head2, 2);
    insertAtEnd(head2, 4);
    insertAtEnd(head2, 6);

    cout << "List 1: ";
    printList(head1);

    cout << "List 2: ";
    printList(head2);

    Node *mergedHead = merge(head1, head2);

    cout << "Merged List: ";
    printList(mergedHead);

    return 0;
}