#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
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
        temp = temp->next; // loop ends here
    temp->next = newNode;
};

bool isPalindrome(Node *head)
{
    if (!head || !head->next)
        return true;
    Node *slow = head;
    Node *fast = head;
    // Step 1: Find middle (slow moves 1, fast moves 2)
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << "Mid is:" << slow->data << endl;
    // Step 2: Reverse the second half
    // if unable to understand how reverse is happening follow this link: https://www.kimi.com/share/19e08fb6-8812-8251-8000-00009e2fd6c4
    Node *prev = nullptr;
    Node *curr = slow->next;
    while (curr)
    {
        Node *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    // Step 3: Compare first half with reversed second half
    Node *left = head;
    Node *right = prev; // head of reversed part
    bool isPalin = true;
    while (right)
    {
        if (left->data != right->data)
        {
            isPalin = false;
            break;
        }
        left = left->next;
        right = right->next;
    }
    return isPalin;
};
void printList(Node *head)
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
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtTail(head, 7);
    insertAtTail(head, 8);
    insertAtTail(head, 9);
    printList(head);
    bool res = isPalindrome(head);
    printList(head);
    cout << "is Plaindrome:" << (res ? "True" : "False") << endl;
    return 0;
}