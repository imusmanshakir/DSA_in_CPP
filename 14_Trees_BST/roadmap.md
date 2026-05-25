# 🌳 Realistic Roadmap to Learn Trees Data Structures

## Rule #1
Do NOT move to the next phase until you can write the current phase’s code from memory on a blank sheet of paper.

## Rule #2
Spend:
- 70% coding
- 30% reading

---

# Phase 0: Fix Recursion First (Days 1–3)

Without recursion, trees will always feel confusing.

## What To Learn

- Base case
- Recursive calls
- Call stack
- Trusting recursion

---

## Practice Problems

- Factorial
- Sum of array
- Print 1 to N
- Print N to 1

---

## Key Insight

```text
Recursion = Trust
```

Trust that:

```cpp
function(smaller_problem)
```

will do its job.

You only focus on:
- current function call
- current node

---

## Mini Exercise

```cpp
#include <iostream>
using namespace std;

void printOneToN(int n)
{
    if (n == 0)
        return;

    printOneToN(n - 1);

    cout << n << " ";
}

int main()
{
    printOneToN(5);

    return 0;
}
```

Output:

```text
1 2 3 4 5
```

---

# Phase 1: Binary Tree Basics (Days 4–10)

---

# 1A. Build The Tree (Days 4–5)

Learn:
- Nodes
- Left/right pointers
- Manual connections

---

## Basic Node Structure

```cpp
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
```

---

## Manual Tree Creation

```cpp
int main()
{
    // Tree:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << root->data << endl;

    return 0;
}
```

---

# 1B. Traversals (Days 6–8)

Master these completely.

---

## Preorder

```text
ROOT → LEFT → RIGHT
```

```cpp
void preorder(Node* root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";

    preorder(root->left);
    preorder(root->right);
}
```

---

## Inorder

```text
LEFT → ROOT → RIGHT
```

```cpp
void inorder(Node* root)
{
    if (root == NULL)
        return;

    inorder(root->left);

    cout << root->data << " ";

    inorder(root->right);
}
```

---

## Postorder

```text
LEFT → RIGHT → ROOT
```

```cpp
void postorder(Node* root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);

    cout << root->data << " ";
}
```

---

# 1C. Level Order Traversal (Days 9–10)

This uses:
- Queue
- BFS

No recursion.

---

## Code

```cpp
#include <queue>

void levelOrder(Node* root)
{
    if (root == NULL)
        return;

    queue<Node*> q;

    q.push(root);

    while (!q.empty())
    {
        Node* current = q.front();

        q.pop();

        cout << current->data << " ";

        if (current->left != NULL)
            q.push(current->left);

        if (current->right != NULL)
            q.push(current->right);
    }
}
```

---

# Phase 1 Checklist

You should be able to:

- Build tree manually
- Write all 3 traversals
- Write level order traversal
- Draw traversal output on paper

---

# Phase 2: Basic Tree Problems (Days 11–18)

Goal:
Learn recursive problem solving on trees.

---

# Problems To Practice

## Height of Tree

```cpp
int height(Node* root)
{
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + max(leftHeight, rightHeight);
}
```

---

## Other Important Problems

- Count nodes
- Count leaf nodes
- Sum of nodes
- Find max/min node
- Diameter of tree

---

# Important Understanding

```text
Return values bubble UP the tree.
```

---

# Phase 2 Checklist

You should:
- solve basic problems without help
- understand recursive return values
- explain why:
  
```cpp
1 + max(left, right)
```

works

---

# Phase 3: Binary Search Tree (BST) (Days 19–28)

BST Rule:

```text
LEFT < ROOT < RIGHT
```

---

# BST Search

```cpp
bool search(Node* root, int key)
{
    if (root == NULL)
        return false;

    if (root->data == key)
        return true;

    if (key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}
```

---

# BST Insert

```cpp
Node* insert(Node* root, int val)
{
    if (root == NULL)
        return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);

    else
        root->right = insert(root->right, val);

    return root;
}
```

---

# BST Advanced

Learn:
- Delete node
- Validate BST
- Inorder predecessor/successor
- Lowest Common Ancestor

---

# Phase 3 Checklist

You should:
- build BST
- search efficiently
- insert correctly
- delete nodes
- validate BST

---

# Phase 4: Self-Balancing Trees (Optional)

Learn concepts only:

- AVL Trees
- Red Black Trees

Understand:
- rotations
- balancing
- why balanced trees matter

Do NOT obsess over memorizing code.

---

# Phase 5: Special Trees

---

# Heap / Priority Queue

Purpose:
- get min/max quickly

Example:

```cpp
#include <queue>

priority_queue<int> pq;

pq.push(10);
pq.push(5);
pq.push(20);

cout << pq.top();
```

Output:

```text
20
```

---

# Trie

Used for:
- autocomplete
- dictionaries
- prefix searching

---

# Segment Tree

Used for:
- range queries
- fast updates

---

# Fenwick Tree

Simpler version of segment tree.

---

# Phase 6: Real Practice

---

# Platforms

## LeetCode
Practice:
- easy
- medium tree problems

---

## GeeksforGeeks
Practice:
- tree section
- BST section

---

# Build Projects

Ideas:
- file explorer
- expression tree
- decision tree

---

# Weekly Schedule

| Day | Work |
|---|---|
| Mon–Tue | Learn concept |
| Wed–Thu | Code from scratch |
| Fri | Solve problems |
| Sat | Review old code |
| Sun | Rest / recursion tracing |

---

# Common Beginner Mistakes

---

## Memorizing Traversal

Wrong.

Always:
- dry run
- draw tree

---

## Skipping Recursion Practice

Trees = recursion heavy.

---

## Jumping To AVL Too Early

Master BST first.

---

## Not Drawing Trees

Always sketch.

---

# Final Advice

Trees are layered learning:

```text
Recursion
    ↓
Binary Tree
    ↓
Traversals
    ↓
BST
    ↓
Balanced Trees
    ↓
Advanced Trees
```

Be patient.

Almost everyone struggles with:

```cpp
inorder(root->left);
```

at first.