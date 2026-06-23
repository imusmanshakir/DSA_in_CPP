#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
static int idx = -1;
Node *buildTree(vector<int> &inorder)
{
    idx++;
    if (inorder[idx] == -1)
        return NULL;

    Node *root = new Node(inorder[idx]);
    root->left = buildTree(inorder);
    root->right = buildTree(inorder);

    return root;
};

// helper function to print inorder traversal
void printInorder(Node *root)
{
    if (root == NULL)
        return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
};

void deleteTree(Node *root)
{
    if (root == NULL)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main()
{
    vector<int> inorder = {1, 2, -1, 3, -1, 4, 5, -1, 6, -1, -1, 7, -1, -1, 8, -1, -1};
    Node *root = buildTree(inorder);
    cout << "Constructed Inorder Tree: ";
    printInorder(root);
    cout << endl;
    deleteTree(root); // cleanup memory

    return 0;
}