#include <bits/stdc++.h> 

 

void inorder(BinaryTreeNode<int> *root, vector<int> &ino){

    if(root==NULL)return;

    inorder(root->left, ino);

    ino.push_back(root->data);

    inorder(root->right, ino); 

}

 

void preorder(BinaryTreeNode<int> *root, vector<int> &pre){

    if(root==NULL)return;

    pre.push_back(root->data);

    preorder(root->left, pre);

    preorder(root->right, pre); 

}

 

void postorder(BinaryTreeNode<int> *root, vector<int> &post){

    if(root==NULL)return;

    postorder(root->left, post);

    postorder(root->right, post); 

    post.push_back(root->data);

}

 

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){

    vector<vector<int>> ans;

    vector<int> ino, pre, post;

    inorder(root, ino);

    preorder(root, pre); 

    postorder(root, post);

    ans.push_back(ino);

    ans.push_back(pre);

    ans.push_back(post);

 

    return ans;

}