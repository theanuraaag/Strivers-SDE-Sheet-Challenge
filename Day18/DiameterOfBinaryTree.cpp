pair<int, int> f(TreeNode<int> *root)
{

    if (root == NULL)
    {

        pair<int, int> p;

        p.first = -1;

        p.second = 0;

        return p;
    }

    pair<int, int> left = f(root->left);

    pair<int, int> right = f(root->right);

    pair<int, int> ans;

    ans.second = max(left.second, max(right.second, left.first + right.first + 2));

    ans.first = max(left.first, right.first) + 1;

    return ans;
}

int diameterOfBinaryTree(TreeNode<int> *root)

{

    return f(root).second;
}