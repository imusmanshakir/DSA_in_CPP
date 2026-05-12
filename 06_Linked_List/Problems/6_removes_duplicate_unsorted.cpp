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

void removeDuplicates(Node *head)
{

    Node *curr = head;

    // Pick one node at a time
    while (curr != nullptr)
    {

        Node *prev = curr;
        Node *temp = curr->next;

        // Check remaining list
        while (temp != nullptr)
        {

            // Duplicate found
            if (curr->data == temp->data)
            {

                prev->next = temp->next;

                Node *duplicate = temp;

                temp = temp->next;

                delete duplicate;
            }
            else
            {

                prev = temp;
                temp = temp->next;
            }
        }

        curr = curr->next;
    }
}

int main()
{

    Node *head = nullptr;

    insertAtEnd(head, 1);
    insertAtEnd(head, 3);
    insertAtEnd(head, 2);
    insertAtEnd(head, 1);
    insertAtEnd(head, 4);
    insertAtEnd(head, 3);
    insertAtEnd(head, 2);

    cout << "Original List:\n";
    printList(head);

    removeDuplicates(head);

    cout << "After Removing Duplicates:\n";
    printList(head);

    return 0;
}

// https://www.kimi.com/share/19e1b066-28d2-808f-8000-0000625ce096