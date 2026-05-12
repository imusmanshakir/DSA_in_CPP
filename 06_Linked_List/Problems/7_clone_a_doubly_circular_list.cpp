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

// Print list
void printList(Node *head)
{

    while (head != nullptr)
    {
        cout << head->data << " -> ";
        head = head->next;
    }

    cout << "NULL\n";
}

Node *cloneList(Node *head)
{

    // Empty list
    if (head == nullptr)
        return nullptr;

    Node *cloneHead = nullptr;
    Node *cloneTail = nullptr;

    Node *temp = head;

    while (temp != nullptr)
    {

        // Create new node
        Node *newNode = new Node(temp->data);

        // First node
        if (cloneHead == nullptr)
        {
            cloneHead = cloneTail = newNode;
        }
        else
        {
            cloneTail->next = newNode;
            cloneTail = newNode;
        }

        temp = temp->next;
    }

    return cloneHead;
}

int main()
{

    Node *head = nullptr;

    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);

    cout << "Original List:\n";
    printList(head);

    Node *clonedList = cloneList(head);

    cout << "Cloned List:\n";
    printList(clonedList);

    return 0;
}

//For step by step guide
// https://www.kimi.com/share/19e1b0c2-3452-83b4-8000-0000befdf6d6