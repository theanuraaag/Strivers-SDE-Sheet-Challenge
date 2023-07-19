#include <bits/stdc++.h>

void Lefttraversal(TreeNode<int> *root, vector<int> &ans)
{

    if (!root)
    {

        return;
    }

    if (root->left == NULL and root->right == NULL)
    {

        return;
    }

    ans.push_back(root->data);

    if (root->left)
    {

        Lefttraversal(root->left, ans);
    }

    else
    {

        Lefttraversal(root->right, ans);
    }
}

void LeafNodeTraversal(TreeNode<int> *root, vector<int> &ans)
{

    if (root == NULL)
    {

        return;
    }

    if (root->left == NULL and root->right == NULL)
    {

        ans.push_back(root->data);

        return;
    }

    LeafNodeTraversal(root->left, ans);

    LeafNodeTraversal(root->right, ans);
}

void RightTraversal(TreeNode<int> *root, vector<int> &ans)
{

    if (root == NULL)
    {

        return;
    }

    if (root->left == NULL and root->right == NULL)
    {

        return;
    }

    if (root->right)
    {

        RightTraversal(root->right, ans);
    }

    else
    {

        RightTraversal(root->left, ans);
    }

    ans.push_back(root->data);
}

vector<int> traverseBoundary(TreeNode<int> *root)
{

    vector<int> ans;

    if (root == NULL)
    {

        return ans;
    }

    ans.push_back(root->data);

    Lefttraversal(root->left, ans);

    LeafNodeTraversal(root->left, ans);

    LeafNodeTraversal(root->right, ans);

    RightTraversal(root->right, ans);

    return ans;
}
