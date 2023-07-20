bool fun(BinaryTreeNode<int> *root1, BinaryTreeNode<int> *root2)

{

    if (root1 == NULL && root2 == NULL)

    {

        return true;
    }

    if (root1->data != root2->data)
    {

        return false;
    }

    return fun(root1->left, root2->right) && fun(root1->right, root2->left);
}

bool isSymmetric(BinaryTreeNode<int> *root)

{

    // Write your code here.

    if (root == NULL)
    {

        return true;
    }

    if ((!root->left && root->right) || (root->left && !root->right))

    {

        return false;
    }

    return fun(root->left, root->right);
}
