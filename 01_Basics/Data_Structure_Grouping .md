# 📚 Data Structures — Complete Categorized Reference

---

## 1. Linear Data Structures

### 🔹 Array

- Fixed-size sequential collection of elements of the same type
- **Access:** O(1) | **Search:** O(n) | **Insert/Delete:** O(n)

### 🔹 Linked List

- Chain of nodes where each node holds data and a pointer to the next
- **Types:** Singly, Doubly, Circular
- **Access:** O(n) | **Insert/Delete (head):** O(1)

### 🔹 Stack

- LIFO (Last In, First Out) structure
- **Operations:** push, pop, peek
- **Use cases:** function call stack, undo/redo, expression parsing

### 🔹 Queue

- FIFO (First In, First Out) structure
- **Types:** Simple, Circular, Deque, Priority Queue
- **Use cases:** scheduling, BFS, buffering

---

## 2. Non-Linear Data Structures

### 🌲 Trees

#### Binary Tree

- Each node has at most 2 children (left, right)

#### Binary Search Tree (BST)

- Left child < Parent < Right child
- **Search/Insert/Delete:** O(log n) avg, O(n) worst

#### AVL Tree

- Self-balancing BST; balance factor ∈ {-1, 0, 1}

#### Red-Black Tree

- Self-balancing BST with color properties; used in `std::map`

#### Heap (Min/Max)

- Complete binary tree; parent ≤ children (Min) or ≥ children (Max)
- **Use cases:** priority queues, heap sort

#### Trie (Prefix Tree)

- Tree for storing strings character by character
- **Use cases:** autocomplete, spell check, IP routing

#### Segment Tree

- Tree for range queries and point updates
- **Operations:** O(log n) query and update

#### Fenwick Tree (Binary Indexed Tree)

- Efficient prefix sum queries and updates
- **Operations:** O(log n)

---

### 🔗 Graphs

- **Representation:** Adjacency Matrix, Adjacency List
- **Types:**
  - Directed / Undirected
  - Weighted / Unweighted
  - Cyclic / Acyclic
  - Connected / Disconnected
  - DAG (Directed Acyclic Graph)
- **Traversals:** BFS — O(V+E) | DFS — O(V+E)

---

## 3. Hash-Based Structures

### 🔸 Hash Table / Hash Map

- Key-value pairs with O(1) avg access via hash function
- **Collision handling:** Chaining, Open Addressing (linear probing, quadratic probing)

### 🔸 Hash Set

- Stores unique elements with O(1) avg lookup

---

## 4. Advanced / Specialized Structures

| Structure                     | Purpose                              | Time Complexity              |
| ----------------------------- | ------------------------------------ | ---------------------------- |
| **Disjoint Set (Union-Find)** | Track connected components           | O(α(n)) amortized            |
| **Skip List**                 | Probabilistic sorted structure       | O(log n) avg                 |
| **Sparse Table**              | Static range minimum/maximum queries | O(1) query, O(n log n) build |
| **Suffix Array**              | Substring search in strings          | O(n log n) build             |
| **B-Tree / B+ Tree**          | Multi-level indexing (databases)     | O(log n)                     |
| **LRU Cache**                 | Least Recently Used eviction policy  | O(1) via HashMap + DLL       |

---

## 5. Complexity Quick Reference

| Structure   | Access   | Search   | Insert   | Delete   | Space |
| ----------- | -------- | -------- | -------- | -------- | ----- |
| Array       | O(1)     | O(n)     | O(n)     | O(n)     | O(n)  |
| Linked List | O(n)     | O(n)     | O(1)     | O(1)     | O(n)  |
| Stack       | O(n)     | O(n)     | O(1)     | O(1)     | O(n)  |
| Queue       | O(n)     | O(n)     | O(1)     | O(1)     | O(n)  |
| Hash Table  | N/A      | O(1) avg | O(1) avg | O(1) avg | O(n)  |
| BST         | O(log n) | O(log n) | O(log n) | O(log n) | O(n)  |
| Heap        | O(1) top | O(n)     | O(log n) | O(log n) | O(n)  |

---

## 6. Choosing the Right Structure

- **Need fast lookup by key?** → Hash Map
- **Need sorted data + range queries?** → BST / Segment Tree
- **Need LIFO behavior?** → Stack
- **Need FIFO behavior?** → Queue
- **Need shortest path in graph?** → BFS (unweighted) / Dijkstra (weighted)
- **Need prefix/word search?** → Trie
- **Need dynamic connectivity?** → Union-Find
- **Need top K elements?** → Heap
