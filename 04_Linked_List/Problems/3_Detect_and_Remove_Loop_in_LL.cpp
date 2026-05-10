#include <iostream>
using namespace std;

struct Node
{
    Node *next;
    int data;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
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
    {
        temp = temp->next;
    }
    temp->next = newNode;
};

bool detectandRemoveLoop(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    // Detect loop
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            // Move slow to head
            slow = head;

            // Find start of loop
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }

            // Find last node of loop
            Node *temp = fast;

            while (temp->next != slow)
            {
                temp = temp->next;
            }

            // Remove loop
            temp->next = nullptr;

            return true;
        }
    }

    return false;
}
// Helper: Create a loop for testing (last node points to 'pos' node)
void createLoop(Node *head, int pos)
{
    if (pos < 0)
        return;

    Node *tail = head;
    while (tail->next) // finding tail
        tail = tail->next;

    Node *loopNode = head; //
    for (int i = 1; i < pos && loopNode; i++)
    {
        loopNode = loopNode->next;
    }
    tail->next = loopNode;
};

void print(Node *head)
{
    while (head)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main()
{
    Node *head = nullptr;
    insertAtTail(head, 10);  // 1 index
    insertAtTail(head, 20);  // 2 index
    insertAtTail(head, 30);  // 3 index
    insertAtTail(head, 40);  // 4 index
    insertAtTail(head, 50);  // 5 index
    insertAtTail(head, 60);  // 6 index
    insertAtTail(head, 70);  // 7 index
    insertAtTail(head, 80);  // 8 index
    insertAtTail(head, 90);  // 9 index
    insertAtTail(head, 100); // 10 index

    print(head);
    createLoop(head, 4);
    cout << (detectandRemoveLoop(head) ? "Loop detected. Removing...done!" : "No loop was found") << endl;
    cout << (detectandRemoveLoop(head) ? "Loop detected. Removing...done!" : "No loop was found") << endl;

    return 0;
}