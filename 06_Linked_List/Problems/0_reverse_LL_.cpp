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
        temp = temp->next;

    temp->next = newNode;
};

void reverse(Node *&head)
{
    Node *prev = nullptr;
    Node *curr = head;
    while (curr)
    {
        Node *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    head = prev;
};

void print(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main()
{
    Node *head = nullptr;
    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);
    insertAtTail(head, 50);
    print(head);
    cout << "Reversing...\n";
    reverse(head);
    print(head);

    return 0;
}

/* you remove head = prev;, here's what will print and why:

10 -> 20 -> 30 -> 40 -> 50 -> NULL
Reversing...
10 -> NULL
Why?
Even though the nodes are reversed, head in main() still points to the old first node (10).
| Step | `curr` | Action               | Result    |
| ---- | ------ | -------------------- | --------- |
| 1    | 10     | `10->next = nullptr` | 10 → NULL |
| 2    | 20     | `20->next = 10`      | 20 → 10   |
| 3    | 30     | `30->next = 20`      | 30 → 20   |
| 4    | 40     | `40->next = 30`      | 40 → 30   |
| 5    | 50     | `50->next = 40`      | 50 → 40   |

*/