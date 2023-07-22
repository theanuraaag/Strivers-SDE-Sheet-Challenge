#include <bits/stdc++.h>

void inorder(BinaryTreeNode<int> *root, vector<int> &v)
{

    if (root == NULL)
        return;

    inorder(root->left, v);

    v.push_back(root->data);

    inorder(root->right, v);
}

pair<int, int> predecessorSuccessor(BinaryTreeNode<int> *root, int key)

{

    // Write your code here.

    vector<int> v;

    inorder(root, v);

    int idx = 0;

    for (int i = 0; i < v.size(); i++)
    {

        if (v[i] == key)
            idx = i;
    }

    pair<int, int> p;

    if (idx == 0)
        p.first = -1;

    else
        p.first = v[idx - 1];

    if (idx == v.size() - 1)
        p.second = -1;

    else
        p.second = v[idx + 1];

    return p;
}
