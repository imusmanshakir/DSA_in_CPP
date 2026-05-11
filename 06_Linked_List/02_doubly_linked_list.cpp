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
    cout << "Deleting " << val << "...\n";
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
    cout << "Searching for " << val << "...\n";
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
    cout << "Insertin " << val << " At " << pos << "\n";
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

void reverse(Node *&head)
{
    // 0 or 1 node — already the same forward/backward
    if (!head || !head->next)
        return;

    Node *temp = head;
    Node *newHead = nullptr;

    while (temp)
    {
        Node *swap = temp->prev;
        temp->prev = temp->next;
        temp->next = swap;

        // The node we just processed will become the new head
        newHead = temp;

        // Move to the next node in the ORIGINAL order.
        // Because we swapped, the original "next" is now in temp->prev.
        temp = temp->prev;
    }

    // Update the head pointer
    head = newHead;
}

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
    deleteByValue(head, 40);
    print(head);
    bool result = search(head, 30);
    cout << (result ? "Found" : "Not found") << "\n";
    cout << "Length of List is: " << getLength(head) << "\n\n";
    insertAtK(head, 40, 3);
    print(head);
    cout << "Reversing...\n";
    reverse(head);
    print(head);

    return 0;
}

// here how swapping is happening in reverse function

/*
 * REVERSE DOUBLY LINKED LIST – STEP BY STEP TRACE
 * List: 30 <-> 20 <-> 10
 * head initially points to 30.
 */

/* INITIAL STATE
 *
 *   head
 *    ↓
 *  ┌────────────┐    ┌────────────┐    ┌────────────┐
 *  │ data: 30   │    │ data: 20   │    │ data: 10   │
 *  │ prev: NULL │    │ prev: &30  │    │ prev: &20  │
 *  │ next: &20  │    │ next: &10  │    │ next: NULL │
 *  └────────────┘    └────────────┘    └────────────┘
 *       ↑                 ↑                 ↑
 *     addr 0x100        addr 0x200        addr 0x300
 */

/* =========================================================================
 * ITERATION 1  (temp = 0x100, i.e. node 30)
 * =========================================================================
 *
 * 1. swap = temp->prev  (temp->prev = NULL)   → swap = NULL
 * 2. temp->prev = temp->next ( = &20 )        → 30->prev = &20
 * 3. temp->next = swap ( = NULL )             → 30->next = NULL
 * 4. newHead = temp                           → newHead = &30
 * 5. temp = temp->prev (now &20)             → temp = &20
 *
 *   AFTER ITERATION 1:
 *   ┌────────────┐    ┌────────────┐    ┌────────────┐
 *   │ data: 30   │    │ data: 20   │    │ data: 10   │
 *   │ prev: &20  │    │ prev: &30  │    │ prev: &20  │
 *   │ next: NULL │    │ next: &10  │    │ next: NULL │
 *   └────────────┘    └────────────┘    └────────────┘
 *        ↑                 ↑                 ↑
 *     0x100             0x200             0x300
 *   (temp moved to 0x200)
 */

/* =========================================================================
 * ITERATION 2  (temp = 0x200, i.e. node 20)
 * =========================================================================
 *
 * 1. swap = temp->prev  (temp->prev = &30)   → swap = &30
 * 2. temp->prev = temp->next ( = &10 )       → 20->prev = &10
 * 3. temp->next = swap ( = &30 )             → 20->next = &30
 * 4. newHead = temp                          → newHead = &20
 * 5. temp = temp->prev (now &10)            → temp = &10
 *
 *   AFTER ITERATION 2:
 *   ┌────────────┐    ┌────────────┐    ┌────────────┐
 *   │ data: 30   │    │ data: 20   │    │ data: 10   │
 *   │ prev: &20  │    │ prev: &10  │    │ prev: &20  │
 *   │ next: NULL │    │ next: &30  │    │ next: NULL │
 *   └────────────┘    └────────────┘    └────────────┘
 *        ↑                 ↑                 ↑
 *     0x100             0x200             0x300
 *   (temp moved to 0x300)
 */

/* =========================================================================
 * ITERATION 3  (temp = 0x300, i.e. node 10)
 * =========================================================================
 *
 * 1. swap = temp->prev  (temp->prev = &20)   → swap = &20
 * 2. temp->prev = temp->next ( = NULL )      → 10->prev = NULL
 * 3. temp->next = swap ( = &20 )             → 10->next = &20
 * 4. newHead = temp                          → newHead = &10
 * 5. temp = temp->prev (now NULL)           → temp = NULL → loop ends
 *
 *   AFTER ITERATION 3:
 *   ┌────────────┐    ┌────────────┐    ┌────────────┐
 *   │ data: 30   │    │ data: 20   │    │ data: 10   │
 *   │ prev: &20  │    │ prev: &10  │    │ prev: NULL │
 *   │ next: NULL │    │ next: &30  │    │ next: &20  │
 *   └────────────┘    └────────────┘    └────────────┘
 *        ↑                 ↑                 ↑
 *     0x100             0x200             0x300
 */

/* FINAL STEP: head = newHead ( = &10 )
 *
 *    head
 *     ↓
 *   ┌────────────┐    ┌────────────┐    ┌────────────┐
 *   │ data: 10   │    │ data: 20   │    │ data: 30   │
 *   │ prev: NULL │<───│ prev: &10  │<───│ prev: &20  │
 *   │ next: &20  │───>│ next: &30  │───>│ next: NULL │
 *   └────────────┘    └────────────┘    └────────────┘
 *
 *   Reversed list: 10 <-> 20 <-> 30
 */
/*
Why temp = temp->prev moves us forward
This is the most confusing part.
After swapping, the original next (which points to the next node in the original sequence) is now stored in prev.
So to continue scanning the original list from left to right, we must follow prev.
temp = [10]
swap its prev and next →
   [10]'s prev = 20   (was next)
   [10]'s next = null  (was prev)
   Now the original pointer that took us to the next node (20) lives in temp->prev.
The old next is gone from its usual place; it's now stored as prev.
So if we want to move to the next node in the original list (20), we must follow temp->prev.

That’s it: after the swap, the “next” pointer of the original direction is now labeled prev.
*/
