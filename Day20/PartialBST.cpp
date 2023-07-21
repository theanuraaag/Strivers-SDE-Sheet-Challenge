#include <bits/stdc++.h>
bool solve(BinaryTreeNode<int> *root, BinaryTreeNode<int> *minNode,
           BinaryTreeNode<int> *maxNode) {
  if (root == nullptr)
    return true;
  if (minNode != nullptr && minNode->data > root->data ||
      maxNode != nullptr && maxNode->data < root->data)
    return false;
  return solve(root->left, minNode, root) && solve(root->right, root, maxNode);
}

bool validateBST(BinaryTreeNode<int> *root) {
  return solve(root, nullptr, nullptr);
}