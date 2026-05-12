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
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

// Remove duplicates
void removeDuplicates(Node *head)
{

    // Empty list
    if (head == nullptr)
        return;

    Node *curr = head;

    while (curr != nullptr && curr->next != nullptr)
    {

        // Duplicate found
        if (curr->data == curr->next->data)
        {

            Node *duplicate = curr->next;

            // Skip duplicate node
            curr->next = curr->next->next;

            delete duplicate;
        }
        else
        {
            // Move forward only if no duplicate
            curr = curr->next;
        }
    }
}

int main()
{

    Node *head = nullptr;

    insertAtEnd(head, 1);
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    insertAtEnd(head, 4);
    insertAtEnd(head, 4);

    cout << "Original List:\n";
    printList(head);

    removeDuplicates(head);

    cout << "After Removing Duplicates:\n";
    printList(head);

    return 0;
}