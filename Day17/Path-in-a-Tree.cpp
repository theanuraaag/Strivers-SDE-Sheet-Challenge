#include <bits/stdc++.h>

bool solve(TreeNode<int> *root, int x, vector<int> &ans)
{

    if (root == NULL)
        return false;

    ans.push_back(root->data);

    if (root->data == x)
        return true;

    if (solve(root->left, x, ans) || solve(root->right, x, ans))
        return true;

    ans.pop_back();

    return false;
}

vector<int> pathInATree(TreeNode<int> *root, int x)

{

    vector<int> ans;

    if (root == NULL)
        return ans;

    solve(root, x, ans);

    return ans;
}