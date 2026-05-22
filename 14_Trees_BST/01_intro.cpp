#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};
// print
void inorder(Node *root) // Inorder Traversal (Left → Root → Right)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
    cout << endl;
}

void preorder(Node *root) // Preorder (Root → Left → Right)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
    cout << endl;
}

void postorder(Node *root) // Postorder (Left → Right → Root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
    cout << endl;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    cout << "in-order traversal\n";
    inorder(root);
    cout << "pre-order traversal\n";
    preorder(root);
    cout << "post-order traversal\n";
    postorder(root);

    return 0;
}