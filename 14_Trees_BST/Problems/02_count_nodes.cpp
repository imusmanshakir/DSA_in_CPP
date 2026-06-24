#include <iostream>
#include <vector>
#include <algorithm>

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
        left = right = nullptr;
    }
};
static int idx = -1;
Node *buildTree(vector<int> &preorder)
{
    idx++;
    if (preorder[idx] == -1)
        return nullptr;

    Node *root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    return root;
};

int countNodes(Node *root)
{
    if (root == nullptr)
        return 0;

    return countNodes(root->left) + countNodes(root->right) + 1;
};

int main()
{
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root = buildTree(preorder);

    cout << "Number of Trees are: " << countNodes(root) << endl;

    return 0;
}

// For step by step guide follow this link:
// https://www.kimi.com/share/19ef8bfd-ff12-8732-8000-0000983d0a62