#include <bits/stdc++.h> 

vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    //  Write your code here.
    if(root==NULL){
        return {};
    }

    queue<BinaryTreeNode<int> *>q1;
    q1.push(root);
    vector<int> ans;
    
    while(!q1.empty()){
        BinaryTreeNode<int> *temp = q1.front();
        ans.push_back(temp->val);

        q1.pop();
        if(temp->left!=NULL) q1.push(temp->left);
        if(temp->right!=NULL) q1.push(temp->right);

    }
    return ans;
}