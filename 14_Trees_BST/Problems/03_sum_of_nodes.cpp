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

int sumOfNodes(Node *root)
{
    if (root == nullptr)
        return 0;
    int leftSum = sumOfNodes(root->left);
    int rightSum = sumOfNodes(root->right);
    return root->data + leftSum + rightSum;
};

int main()
{
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root = buildTree(preorder);

    cout << "Sum of Tree is: " << sumOfNodes(root) << endl;

    return 0;
}

// For step by step guide follow this link:
// https://www.kimi.com/share/19ef8e43-0d62-86cc-8000-00004e18b0d8