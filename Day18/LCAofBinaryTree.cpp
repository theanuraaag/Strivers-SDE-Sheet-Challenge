#include <bits/stdc++.h> 


int lowestCommonAncestor(TreeNode<int> *root, int x, int y){

    //    Write your code here

    if(root == NULL){

        return -1;

    }

    if(root->data == x || root->data ==y){

        return root->data;

    }

    int left=lowestCommonAncestor(root->left,x,y);

    int right=lowestCommonAncestor(root->right,x,y);

    if(left == -1){

        return right;

    }

    else if(right == -1){

        return left;

    }

    return root->data;

}

