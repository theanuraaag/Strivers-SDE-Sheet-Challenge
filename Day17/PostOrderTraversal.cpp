#include <bits/stdc++.h>
void post(TreeNode *root, vector<int> &v) {
  if (root == NULL) {
    return;
  }
  post(root->left, v);
  post(root->right, v);
  v.push_back(root->data);
  return;
}

vector<int> getPostOrderTraversal(TreeNode *root) {
  vector<int> v;
  post(root, v);
  return v;
}
