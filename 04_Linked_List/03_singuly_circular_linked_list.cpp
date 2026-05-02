#include <iostream>
using namespace std;

struct Node
{
    int data;
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
    if (head == nullptr)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        Node *last = head;

        while (last->next != head)
            last = last->next; // loop ends here

        newNode->next = head; // step 1: new node points to old head
        last->next = newNode; // step 2: *** HERE *** old tail now points to the new node
        head = newNode;       // step 3: update head to the new node
    }
};

void insertAtTail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == nullptr)
    {
        head = newNode;
        newNode->next = head;
    }
    Node *last = head;
    while (last->next != head)
        last = last->next;

    last->next = newNode;
    newNode->next = head;
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
    Node *tail = head;
    while (tail->next != head)
        tail = tail->next; // loop ends here
    Node *oldhead = head;
    head = head->next;
    tail->next = head;
    delete oldhead;
}

void deleteTail(Node *&head)
{
    if (!head)
    {
        return;
    }
    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }
    Node *secodlastNode = head;
    while (secodlastNode->next->next != head)
        secodlastNode = secodlastNode->next;

    Node *tail = secodlastNode->next;
    secodlastNode->next = head;
    Node *deleteTail = tail;
    delete deleteTail;
};

void deleteByValue(Node *&head, int val)
{
    cout << "Deleting " << val << "...\n";
    if (!head)
        return;

    if (head->next == head)
    {
        if (head->data == val)
        {
            delete head;
            head = nullptr;
        }
        return;
    }

    Node *curr = head;
    Node *prev = nullptr;
    // First, check if the head itself is the node to delete
    if (head->data == val)
    {
        Node *tail = head;
        while (tail->next != head)
            tail = tail->next;

        Node *oldHead = head;
        head = head->next;
        tail->next = head;
        delete oldHead;
    }

    // Otherwise, search for the value starting from the second node
    prev = head;
    curr = head->next;
    while (curr != head && curr->data != val)
    {
        prev = curr;
        curr = curr->next;
    }
    if (curr == head)
    {
        cout << "oops!Position out of range\n";
        return;
    }
    prev->next = curr->next;
    delete curr;
};

bool search(Node *head, int val)
{
    cout << "Searching for " << val << "...\n";

    Node *temp = head;
    while (temp != head)
    {
        if (temp->data == val)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void insertAtK(Node *&head, int val, int pos)
{
    cout << "Inserting " << val << " at Position " << pos << "...\n";
    if (pos <= 0)
    {
        cout << "Inavalid Position\n";
        return;
    }
    if (pos == 1 || head == nullptr)
    {
        insertAtHead(head, val);
        return;
    }
    int currentPos = 1;
    Node *prev = head;
    while (currentPos < pos - 1 && prev != head)
    {
        prev = prev->next;
        currentPos++;
    }
    // Now prev is the node after which we insert.
    // If we reached the tail before count == k-1, prev is the tail.
    // That's perfectly fine – insert after tail.
    Node *newNode = new Node(val);
    newNode->next = prev->next;
    prev->next = newNode;
};

void reverse(Node *&head)
{
    if (!head || head->next == head)
        return;

    Node *oldHead = head;
    Node *prev = nullptr;
    Node *curr = head;
    Node *next = nullptr;

    // if you are unable to understand how reversing is happening have a look at this demonstration by gpt: https://chatgpt.com/share/69f61a08-907c-83e8-8917-08137a0776f0
    do
    {
        next = curr->next;
        curr->next = prev; // This is the actual reversing step.We reversed direction of arrow.
        prev = curr;
        curr = next;
    } while (curr != oldHead);

    head = prev;
    oldHead->next = head;
}

int getLength(Node *head)
{
    Node *temp = head;
    int count = 0;
    do
    {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

void print(Node *head)
{
    if (!head)
        return;
    Node *temp = head;
    cout << "LIST:";
    do
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "Back to head <-\n";
};
int main()
{
    Node *head = nullptr;
    cout << "Inserting at head:\n";
    insertAtHead(head, 50);
    insertAtHead(head, 40);
    insertAtHead(head, 30);
    insertAtHead(head, 20);
    insertAtHead(head, 10);
    print(head);
    cout << "\nInserting at tail:\n";
    insertAtTail(head, 60);
    print(head);
    deleteHead(head);
    cout << "\nRemoving head...\n";
    print(head);
    cout << "\nRemoving tail...\n";
    deleteTail(head);
    print(head);
    cout << "\n";
    deleteByValue(head, 100);
    print(head);
    cout << "\n";
    bool result = search(head, 70);
    cout << (result ? "Found" : "Not Found\n");
    cout << "\n";
    insertAtK(head, 100, 1);
    print(head);
    cout << "\nReversing...\n";
    reverse(head);
    print(head);
    int length = getLength(head);
    cout << "\nLength of List is: " << length << endl;

    return 0;
}