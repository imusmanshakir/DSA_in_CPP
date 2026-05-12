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
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

Node *swapPairs(Node *head)
{

    if (head == nullptr || head->next == nullptr)
        return head;

    Node *prev = nullptr;
    Node *first = head;

    // New head will become second node
    head = head->next;

    while (first != nullptr && first->next != nullptr)
    {

        Node *second = first->next;
        Node *third = first->next->next;

        // Swap
        second->next = first;
        first->next = third;

        // Connect previous pair
        if (prev != nullptr)
        {
            prev->next = second;
        }

        // Move prev
        prev = first;

        // Move curr to next pair
        first = third;
    }

    return head;
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

    head = swapPairs(head);

    cout << "After Swapping Pairs:\n";
    printList(head);

    return 0;
}

// Follow to view step by step guide
// https: // www.kimi.com/share/19e1af56-0862-8c5b-8000-0000b84fc116