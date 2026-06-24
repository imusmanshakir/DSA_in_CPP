#include <iostream>
#include <vector>
#include <queue>

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

Node *buildTree(vector<int> &levelorder)
{
    idx++;
    if (levelorder[idx] == -1)
        return nullptr;

    Node *root = new Node(levelorder[idx]);

    root->left = buildTree(levelorder);
    root->right = buildTree(levelorder);

    return root;
}

void levelOrder(Node *root)
{
    if (root == nullptr)
        return;

    queue<Node *> q;
    q.push(root);
    q.push(nullptr);
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        if (curr == nullptr)
        {
            if (!q.empty())
            {
                cout << endl;
                q.push(nullptr);
                continue;
            }
            else
            {
                break;
            }
        }
        cout << curr->data << " ";
        if (curr->left != nullptr)
            q.push(curr->left);
        if (curr->right != nullptr)
            q.push(curr->right);
    }
    cout << endl;
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
    vector<int> levelorder = {1, 2, 4, -1, -1, -1, 3, 5, 6, -1, -1, -1, -1};

    Node *root = buildTree(levelorder);

    cout << "Constructed level-Order Tree is: \n";
    levelOrder(root);

    deleteTree(root);
    return 0;
}

// For step by step guide follow this link:
// https://www.kimi.com/share/19ef4338-abb2-8730-8000-000026d3d045
// https://www.kimi.com/share/19ef839e-c592-86d7-8000-00001b6dcd67