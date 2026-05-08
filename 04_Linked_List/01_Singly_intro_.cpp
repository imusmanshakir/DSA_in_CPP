#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data; // this->data is exactly equivalent to (*this).data
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
        return;
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
        return;
    Node *todelete = temp->next;
    temp->next = temp->next->next; // bypass node
    delete todelete;
}

void insertAtK(Node *&head, int val, int pos)
{
    if (pos <= 0)
    {
        cout << "Invalid Position\n";
        return;
    }
    if (pos == 1)
    {
        insertAtHead(head, val);
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
        delete newNode;
        return;
    }
    newNode->next = temp->next; // temp->next is currently nullptr (since node 40 was the tail).So newNode->next becomes nullptr.
    temp->next = newNode;
};

// understands what is happening behind the scene: https://www.kimi.com/share/19e08c54-78e2-8975-8000-0000a88a3d97
void reverse(Node *&head)
{
    if (!head)
    {
        return;
    }
    Node *prev = nullptr;
    Node *curr = head;

    while (curr) // or you can say while(curr != nullptr)
    {
        Node *nextNode = curr->next; // to iterate over linked list.
        curr->next = prev;           // That line changes arrow direction.Everything else is just:saving nodes,avoiding data loss,moving pointers
        prev = curr;
        curr = nextNode; // assiging new value
    }
    head = prev;
};

Node *reverse1(Node *head)
{
    // Base case: empty list or single node
    if (head == nullptr || head->next == nullptr)
        return head;

    // Recursive call on the rest of the list
    Node *newHead = reverse1(head->next);

    // Rewiring step:
    head->next->next = head; // make the next node point back to current
    head->next = nullptr;    // current node becomes the new tail

    return newHead; // always return the (unchanged) new head
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
    cout << "LIST: ";

    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "\n\n";
}

int main()
{
    Node *head = nullptr;
    cout << "Inserting values at head:\n";
    insertAtHead(head, 40);
    insertAtHead(head, 30);
    insertAtHead(head, 20);
    insertAtHead(head, 10);
    print(head);
    cout << "Inserting at tail and then removing:\n";
    insertAtTail(head, 50);
    print(head);
    deleteAtTail(head);
    print(head);
    cout << "Removing head:\n";
    deleteHead(head);
    print(head);
    cout << "Deleting by value 30:\n";
    deleteByValue(head, 30);
    print(head);
    bool found = searchValue(head, 40);
    cout << "Searching for 40: " << (found ? "Found" : "Not found") << endl;
    cout << "Length of list:" << getLength(head) << endl;
    cout << "Inserting new node...\n";
    insertAtK(head, 30, 2);
    print(head);
    cout << "Reversing...\n";
    reverse(head);
    print(head);

    return 0;
}

/*
+---------------------------+-------------------------------------+-----------------------------+
| What you write            | What it means                       | Result                      |
+---------------------------+-------------------------------------+-----------------------------+
| temp                      | The pointer itself                  | address 0x100               |
| *temp                     | The node object at that address     | {data:10, next:0x200}       |
| temp->data                | The data value inside *temp         | 10                          |
| temp->next                | The next pointer inside *temp       | 0x200 (address of 2nd node) |
| temp->next->data          | The data value of the second node   | 20                          |
| temp->next->next->data    | The data value of the third node    | 30                          |
+---------------------------+-------------------------------------+-----------------------------+
*/