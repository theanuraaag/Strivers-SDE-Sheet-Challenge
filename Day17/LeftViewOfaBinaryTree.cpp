void recursion(TreeNode<int> *root, int level, vector<int> &ds)

{

    if (root == NULL)
        return;

    if (ds.size() == level)
        ds.push_back(root->data);

    recursion(root->left, level + 1, ds);
    recursion(root->right, level + 1, ds);
}
vector<int> getLeftView(TreeNode<int> *root)

{

    //    Write your code here

    vector<int> ds;

    recursion(root, 0, ds);

    return ds;
}