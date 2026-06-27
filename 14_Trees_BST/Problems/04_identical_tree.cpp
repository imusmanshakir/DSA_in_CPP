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

Node *buildTreeHelper(vector<int> &preorder, int &idx)
{
    idx++;
    if (preorder[idx] == -1)
        return nullptr;

    Node *root = new Node(preorder[idx]);
    root->left = buildTreeHelper(preorder, idx);
    root->right = buildTreeHelper(preorder, idx);
    return root;
};

Node *buildTree(vector<int> &preorder)
{
    int idx = -1;
    return buildTreeHelper(preorder, idx);
}

bool isIdentical(Node *p, Node *q)
{
    if (p == nullptr && q == nullptr)
        return true;
    if (p == nullptr || q == nullptr)
        return false;

    return (p->data == q->data) && isIdentical(p->left, q->left) && isIdentical(p->right, q->right);
};

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
    vector<int> preorder1 = {1, 2, -1, -1, 3, -1, -1};
    vector<int> preorder2 = {1, 2, -1, -1, 3, -1, -1};
    Node *tree1 = buildTree(preorder1);
    Node *tree2 = buildTree(preorder2);
    if (isIdentical(tree1, tree2))
    {
        cout << "The trees are identical." << endl;
    }
    else
    {
        cout << "The trees are not identical." << endl;
    }

    deleteTree(tree1);
    deleteTree(tree2);

    return 0;
}

// For step by step guide follow this link:
// https://www.kimi.com/share/19f09ea0-2202-8a92-8000-0000a912e352