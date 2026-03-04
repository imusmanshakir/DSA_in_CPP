#include <iostream>
using namespace std;

// Node definition
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Insert at head
void insertAtHead(Node*& head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

// Insert at tail
void insertAtTail(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

// Delete at head
void deleteAtHead(Node*& head) {
    if (!head) return;
    Node* toDelete = head;
    head = head->next;
    delete toDelete;
}

// Delete by value (first occurrence)
void deleteByValue(Node*& head, int val) {
    if (!head) return;
    if (head->data == val) {
        deleteAtHead(head);
        return;
    }
    Node* temp = head;
    while (temp->next && temp->next->data != val)
        temp = temp->next;
    if (!temp->next) return; // value not found
    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

// Print list
void printList(Node* head) {
    cout << "List: ";
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = nullptr;

    // Demo: fixed inserts & deletes
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    printList(head); // 1 -> 2 -> 3 -> NULL

    insertAtTail(head, 4);
    insertAtTail(head, 5);
    printList(head); // 1 -> 2 -> 3 -> 4 -> 5 -> NULL

    deleteByValue(head, 3);
    printList(head); // 1 -> 2 -> 4 -> 5 -> NULL

    deleteAtHead(head);
    printList(head); // 2 -> 4 -> 5 -> NULL

    // Clean up remaining nodes
    while (head) deleteAtHead(head);
    return 0;
}
