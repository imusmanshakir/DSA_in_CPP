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

// for step by step guide
// https://www.kimi.com/share/19e11dd9-a652-8532-8000-00008d49e17e

// Floyd's algorithm works because fast (2×) and slow (1×) have a relative speed of exactly 1 node per iteration.
// This guarantees they will land on the same node — they can never "pass through" each other.
/*Explanation:
   ============================================================================
   FLOYD'S CYCLE DETECTION ALGORITHM (Tortoise and Hare)
   ============================================================================

   PROBLEM: Detect if a linked list has a loop (cycle), find where it starts,
            and break it.

   WHY THIS WORKS (The Intuition):
   --------------------------------
   Imagine two runners on a circular track:
   - Slow runner (Tortoise) moves 1 step per second
   - Fast runner (Hare) moves 2 steps per second

   If the track is circular, the Hare MUST eventually catch up to the Tortoise
   from behind. They are guaranteed to meet at SOME point on the circle.

   If there is no circle (list ends in NULL), the Hare reaches the end first.

   THE MATH PROOF (Why they meet):
   --------------------------------
   Let:  m = distance from HEAD to loop start
         n = distance from loop start to meeting point
         k = length of the loop

   When slow and fast first meet:
   - Slow has traveled:  m + n
   - Fast has traveled:  m + n + p*k  (some full laps, p ≥ 1)

   Since Fast is 2x speed:
        2(m + n) = m + n + p*k
   =>   m + n = p*k
   =>   m = p*k - n

   This means: walking 'm' steps from HEAD is the same as walking 'm' steps
   from the meeting point (which equals p*k - n, i.e., some full laps minus n).

   Therefore, if we reset one pointer to HEAD and move both at 1x speed,
   they will meet exactly at the LOOP START.

   PHASE 1: DETECTION
   ------------------
   - Initialize slow = head, fast = head
   - Move slow by 1, fast by 2
   - If fast reaches NULL → no loop exists
   - If slow == fast → loop detected! (they met somewhere inside the loop)

   PHASE 2: FIND LOOP START
   ------------------------
   - Reset slow = head (keep fast at meeting point)
   - Move BOTH by 1 step now
   - The node where they meet is the START of the loop

   PHASE 3: REMOVE LOOP
   --------------------
   - Start from the loop start node
   - Traverse until you find the node whose next points back to start
   - Set that next pointer to NULL

   WHY CAN'T THEY "PASS THROUGH" EACH OTHER?
   -----------------------------------------
   Fast gains exactly 1 node on Slow per iteration (relative speed = 1).
   Since movement is discrete (node-to-node), when the gap is 1, the next
   step makes them land on the SAME node. They can never skip past each other.

   COMPLEXITY:
   -----------
   Time:  O(n)  — single traversal for detection, single for finding start
   Space: O(1)  — only two pointers used

   EDGE CASES HANDLED:
   -------------------
   1. Empty list (head == nullptr)
   2. Single node with no loop
   3. Single node with self-loop
   4. Loop at head (entire list is circular)
   5. Multiple nodes in loop tail

   COMMON MISTAKES TO AVOID:
   -------------------------
   - Don't forget to check BOTH fast != nullptr AND fast->next != nullptr
   - After finding meeting point, reset slow to HEAD, not slow to some other node
   - When breaking loop, traverse from loop start until temp->next == loopStart
     (not until temp == loopStart, otherwise you stop immediately)

   EXAMPLE TRACE (10→20→30→40→50→60→70→80→90→100, loop at 50):
   -------------------------------------------------------------
   Phase 1 (Detection):
      Iter 1: slow=20,  fast=30
      Iter 2: slow=30,  fast=50
      Iter 3: slow=40,  fast=70
      Iter 4: slow=50,  fast=90
      Iter 5: slow=60,  fast=50   (90→100→50)
      Iter 6: slow=70,  fast=70   (50→60→70)  ← MEET!

   Phase 2 (Find Start):
      Reset slow=10, fast stays at 70
      Step 1: slow=20,  fast=80
      Step 2: slow=30,  fast=90
      Step 3: slow=40,  fast=100
      Step 4: slow=50,  fast=50   (100→50)  ← LOOP START!

   Phase 3 (Break):
      temp=50→60→70→80→90→100,  100->next is 50, so break: 100->next=nullptr
   ============================================================================
*/
