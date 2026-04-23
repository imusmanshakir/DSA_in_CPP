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

void insert(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
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
}



void print(Node *&head)
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
    Node *head = NULL;
    Node *node1 = new Node(10);
    insert(head, 20);
    insert(head, 30);
    insert(head, 40);
    print(head);

    return 0;
}
