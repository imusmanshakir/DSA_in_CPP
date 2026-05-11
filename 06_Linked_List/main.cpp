#include <iostream>
using namespace std;

struct Node
{
    int data = 1;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

void insertAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head; // We are storing the value of head (an address) inside newNode->next OR Connect new node to old list
    head = newNode;
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
        temp = temp->next; // loop ends here

    temp->next = newNode;
}

void deleteHead(Node *&head)
{
    if (!head)
    {
        return;
    }
    Node *toDelete = head;
    head = head->next;
    delete toDelete;
};

void deleteAtTail(Node *&head)
{
    if (!head)
    {
        return;
    }
    if (!head->next)
    {
        delete head;
        head = nullptr;
    }
    Node *temp = head;
    while (temp->next->next)
        temp = temp->next; // loop ends here

    delete temp->next;
    temp->next = nullptr;
};

void deleteByValue(Node *&head, int val)
{
    if (!head)
    {
        return;
    }
    if (head->data == val)
    {
        deleteHead(head);
        return;
    }
    Node *temp = head;
    while (temp->next && temp->next->data != val)
        temp = temp->next; // loop ends here

    if (!temp->next)
    {
        return;
    }
    Node *todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}

bool searchValue(Node *head, int val)
{
    Node *temp = head;
    while (temp)
    {
        if (temp->data == val)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
};

void print(Node *head)
{
    cout << "LIST: ";

    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = nullptr;
    cout << "Inserting values at head:" << endl;
    insertAtHead(head, 40);
    insertAtHead(head, 30);
    insertAtHead(head, 20);
    insertAtHead(head, 10);
    print(head);
    cout << "Inserting at tail and then removing:" << endl;
    insertAtTail(head, 50);
    print(head);
    deleteAtTail(head);
    print(head);
    cout << "Removing head:" << endl;
    deleteHead(head);
    print(head);
    cout << "Deleting by value 30:" << endl;
    deleteByValue(head, 30);
    print(head);
    bool found = searchValue(head, 40);
    cout << "Searching for 40: " << (found ? "Found" : "Not found") << endl;
    // print(head);

    return 0;
}
