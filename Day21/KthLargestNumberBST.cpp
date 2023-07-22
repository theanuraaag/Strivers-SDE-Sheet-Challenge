#include <bits/stdc++.h> 


void findKthLarge(TreeNode<int>*root, int &ans,int &k){
    if(!root || k <= 0) return;
    findKthLarge(root->right, ans, k);
    k--;
    if(k == 0){
        ans = root->data;
        return;
    }
    findKthLarge(root->left, ans, k);
}

int KthLargestNumber(TreeNode<int>* root, int k) 
{
    int ans = -1;
    findKthLarge(root, ans, k);
    return ans;
}
