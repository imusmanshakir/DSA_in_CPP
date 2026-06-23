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
// Fixed function: Builds the tree recursively using the preorder vector
Node *buildTree(vector<int> &preorder)
{
    idx++;

    if (preorder[idx] == -1)
        return nullptr;

    Node *root = new Node(preorder[idx]);

    // Recursively construct the left and right subtrees
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);

    return root;
}

// Helper function to print the tree in preorder to verify correctness
void printPreorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void deleteTree(Node *root)
{
    if (root == nullptr)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main()
{
    vector<int> preorder = {1, 2, 3, -1, -1, -1, 4, 5, -1, -1, -1};

    Node *root = buildTree(preorder);

    // Verify the construction by printing the values back out
    cout << "Constructed Tree Preorder: ";
    printPreorder(root);
    cout << endl;

    deleteTree(root); // Clean up memory!

    return 0;
}

// for step by step guide follow this link:
//  https://www.kimi.com/share/19ef3947-3b52-8d13-8000-0000530c728b
