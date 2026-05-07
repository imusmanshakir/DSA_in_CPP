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
void insertAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (!head)
    {
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
        return;
    }
    Node *oldHead = head;
    Node *tail = oldHead->prev;
    newNode->next = oldHead;
    newNode->prev = tail;
    tail->next = newNode;
    oldHead->prev = newNode;
};

void insertAtTail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (!head)
    {
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
        return;
    }
    Node *tail = head->prev;
    tail->next = newNode;
    newNode->prev = tail;
    newNode->next = head;
    head->prev = newNode;
};

void deleteHead(Node *&head)
{
    if (head == nullptr)
        return;
    if (head->next == head)
    {
        delete head;
        head = nullptr;
        return;
    }
    Node *oldHead = head;
    Node *tail = oldHead->prev;
    head = head->next;
    tail->next = head;
    head->prev = tail;
    delete oldHead;
};

void deleteTail(Node *&head)
{
    if (!head)
        return;
    if (head->next == head)
    {
        delete head;
        head = nullptr;
        return;
    }

    Node *oldTail = head->prev;
    Node *secondLastTail = oldTail->prev;
    secondLastTail->next = head;
    head->prev = secondLastTail;
    delete oldTail;
};

void deleteByValue(Node *&head, int val)
{
    cout << "Deleting... " << val << "\n";
    if (!head)
        return;
    // if only head exists
    if (head->next == head && head->data == val)
    {

        delete head;
        head = nullptr;
        return;
    }

    // First, check if the head itself is the node to delete
    if (head->data == val)
    {
        Node *tail = head->prev;
        Node *newHead = head->next;
        tail->next = newHead;
        newHead->prev = tail;
        delete head;
        head = newHead;
        return;
    }

    // Otherwise, search for the value starting from the second node
    Node *curr = head->next;
    while (curr != head)
    {
        if (curr->data == val)
        {
            Node *prevNode = curr->prev;
            Node *nextNode = curr->next;
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
            delete curr;
            return;
        }
        curr = curr->next;
    }
};

bool search(Node *head, int val)
{
    cout << "Searching for " << val << "...\n";
    Node *curr = head;
    do
    {
        if (curr->data == val)
        {
            return true;
        }
        curr = curr->next;
    } while (curr != head);
    return false;
};

void insertAtK(Node *&head, int val, int pos)
{
    cout << "Inserting " << val << " at Position " << pos << "...\n";
    if (pos <= 0)
    {
        cout << "oops! Invalid Position.\n";
        return;
    }
    if (pos == 1)
    {
        insertAtHead(head, val);
        return;
    }
    int currentPos = 1;
    Node *curr = head;
    while (currentPos < pos - 1 && curr->next != head)
    {
        curr = curr->next;
        currentPos++;
    }
    Node *newNode = new Node(val);
    Node *nextNode = curr->next;
    newNode->next = nextNode;
    newNode->prev = curr;
    nextNode->prev = newNode;
    curr->next = newNode;
};

void reverse(Node *&head)
{
    if (!head || head->next == head)
        return;

    // The old tail will become the new head after reversal
    Node *newHead = head->prev;
    Node *curr = head;
    do
    {
        Node *nextNode = curr->next;
        // now swap the two pointers
        curr->next = curr->prev;
        curr->prev = nextNode;
        curr = nextNode;
    } while (curr != head);
    head = newHead;
}

int getLength(Node *head)
{
    if (!head)
    {
        return 0;
    }
    Node *curr = head;
    int count = 0;
    do
    {
        count++;
        curr = curr->next;
    } while (curr != head);
    return count;
};

void print(Node *head)
{
    if (!head)
    {
        cout << "LIST is empty\n";
        return;
    }
    // priting forward
    Node *forward = head;
    cout << "Forward:->";
    do
    {
        cout << forward->data << " -> ";
        forward = forward->next;
    } while (forward != head);
    cout << " Back to head <-\n";
    // printing backward
    Node *tail = head->prev;
    cout << "Backward:";
    cout << " -> Back to tail ";
    do
    {
        cout << tail->data << " <- ";
        tail = tail->prev;
    } while (tail != head->prev);

    cout << "\n\n";
}

int main()
{
    Node *head = nullptr;
    cout << "Inserting at head\n";
    insertAtHead(head, 10);
    insertAtHead(head, 20);
    insertAtHead(head, 30);
    print(head);
    cout << "Inserting at tail\n";
    insertAtTail(head, 40);
    insertAtTail(head, 50);
    insertAtTail(head, 60);
    print(head);
    cout << "Deleting head...\n";
    deleteHead(head);
    print(head);
    cout << "Deleting tail...\n";
    deleteTail(head);
    print(head);
    deleteByValue(head, 20);
    print(head);
    bool result = search(head, 40);
    cout << (result ? "Found\n" : "Not found\n") << endl;
    insertAtK(head, 100, 3);
    print(head);
    cout << "\nReversing...\n";
    reverse(head);
    print(head);
    int length = getLength(head);
    cout << "Length of List is: " << length << endl;

    return 0;
}