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
Node *buildTree(vector<int> &postorder)
{
    idx++;
    if (postorder[idx] == -1)
        return NULL;
    Node *root = new Node(postorder[idx]);
    // recursivley building tree for left and right subtrees
    root->left = buildTree(postorder);
    root->right = buildTree(postorder);

    return root;
};

void printpostOrder(Node *root)
{
    if (root == NULL)
        return;
    printpostOrder(root->left);
    printpostOrder(root->right);
    cout << root->data << " ";
};

void deleteNode(Node *root)
{
    if (root == NULL)
        return;

    deleteNode(root->left);
    deleteNode(root->right);
    delete root;
}

int main()
{
    vector<int> postorder = {1, 2, -1, 3, 4, -1, 5, -1, -1, 6, -1, -1, 7, -1, -1};
    Node *root = buildTree(postorder);
    cout << "Constructed Post-Order Tree is: \n";
    printpostOrder(root);
    cout << endl;
    deleteNode(root); // cleanup memory

    return 0;
}