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
};

bool isIdentical(Node *tree1, Node *tree2)
{
    if (tree1 == nullptr && tree2 == nullptr)
        return true;
    if (tree1 == nullptr || tree2 == nullptr)
        return false;
    return tree1->data == tree2->data && isIdentical(tree1->left, tree2->left) && isIdentical(tree1->right, tree2->right);
};
bool isSubtree(Node *mainTree, Node *subTree)
{
    if (subTree == nullptr)
        return true;
    if (mainTree == nullptr)
        return false;
    if (isIdentical(mainTree, subTree))
        return true;

    return isSubtree(mainTree->left, subTree) || isSubtree(mainTree->right, subTree);
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
    vector<int> preorder1 = {3, 4, 1, -1, -1, -1, -1, 5, -1};
    vector<int> preorder2 = {4, 1, -1, -1, 2, -1, -1};
    Node *tree1 = buildTree(preorder1);
    Node *tree2 = buildTree(preorder2);
    if (isSubtree(tree1, tree2))
    {
        cout << "The tree1 is identical to tree2." << endl;
    }
    else
    {
        cout << "The tree1 is not identical to tree2." << endl;
    }

    deleteTree(tree1);
    deleteTree(tree2);
    return 0;
}

// For step by step guide follow this link
// https://www.kimi.com/share/19f0a351-8cf2-811f-8000-0000c3792f2e