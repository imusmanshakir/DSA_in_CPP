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

void inserAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    if (head != nullptr)
    {
        head->prev = newNode;
    }
    head = newNode;
};

void insertAtTail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
};

void deleteHead(Node *&head)
{
    if (!head)
    {
        return;
    }
    if (head->next == nullptr)
    {
        delete head;
        return;
    }
    Node *todelete = head;
    head = head->next;
    head->prev = nullptr;
    delete todelete;
};

void deleteTail(Node *&head)
{
    if (!head)
    {
        return;
    }
    if (!head->next)
    {
        delete head;
        head = nullptr;
        return;
    }
    Node *temp = head;
    while (temp->next)
        temp = temp->next;

    Node *todelete = temp;
    temp = temp->prev;
    temp->next = nullptr;
    delete todelete;
};

void deleteByValue(Node *&head, int val)
{
    // 1. Empty list – nothing to delete
    if (!head)
        return;

    Node *temp = head;
    while (temp)
    {
        if (temp->data == val)
        {
            if (temp->prev == nullptr) // Case A: it's the head
            {
                head = head->next;        // move head forward
                if (head)                 // if new head exists
                    head->prev = nullptr; // cut backward link
            }
            else if (temp->next == nullptr) // Case B: it's the tail
            {
                temp->prev->next = nullptr; // cut forward link of previous node
            }
            else // Case C: it's in the middle
            {
                temp->prev->next = temp->next; // bypass forward
                temp->next->prev = temp->prev; // bypass backward
            }

            delete temp; // free the node
            return;      // job done (delete first occurrence only)
        }
        temp = temp->next; // move to next node
    }
    // 3. Value not found – silently return
    return;
}

bool search(Node *head, int val)
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

void insertAtK(Node *&head, int val, int pos)
{
    if (pos <= 0)
    {
        cout << "Invalid Position\n";
        return;
    }
    if (pos == 1)
    {
        inserAtHead(head, val);
        return;
    }
    Node *newNode = new Node(val);
    Node *temp = head;
    int currentPos = 1;
    while (temp && currentPos < pos - 1)
    {
        temp = temp->next;
        currentPos++;
    }

    if (!temp)
    {
        cout << "Position out of range\n";
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next = newNode;
    if (newNode->next != nullptr)
        newNode->next->prev = newNode;
};

int getLength(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    return count;
};

void print(Node *head)
{
    if (!head)
    {
        cout << "LIST:Empty\n";
        return;
    }
    Node *temp = head;
    cout << "Forward:  ";
    while (temp)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "\n";
    temp = head;
    while (temp->next)
        temp = temp->next;

    cout << "Backward: ";
    while (temp)
    {
        cout << temp->data << " <- ";
        temp = temp->prev;
    }
    cout << "\n\n";
}

int main()
{
    Node *head = nullptr;
    cout << "Inserting at head\n";
    inserAtHead(head, 50);
    inserAtHead(head, 40);
    inserAtHead(head, 30);
    inserAtHead(head, 20);
    inserAtHead(head, 10);
    print(head);
    cout << "Inserting at tail\n";
    insertAtTail(head, 60);
    print(head);
    cout << "Removing head\n";
    deleteHead(head);
    print(head);
    cout << "Removing tail\n";
    deleteTail(head);
    print(head);
    cout << "Deleting 40...\n";
    deleteByValue(head, 40);
    print(head);
    bool result = search(head, 30);
    cout << "Searching for 30..." << (result ? "Found" : "Not found") << "\n";
    cout << "Length of List is: " << getLength(head) << "\n\n";
    cout << "Inserting 40 at 3...\n";
    insertAtK(head, 40, 3);
    print(head);

    return 0;
}