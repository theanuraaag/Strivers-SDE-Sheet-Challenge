#include <bits/stdc++.h>
void connectNodes(BinaryTreeNode<int> *root) {

  if (root == NULL)
    return;

  queue<BinaryTreeNode<int> *> q;

  q.push(root);

  while (!q.empty()) {

    int size = q.size();

    BinaryTreeNode<int> *currNode, *prevNode = NULL;

    for (int i = 0; i < size; i++) {

      currNode = q.front();

      q.pop();

      if (currNode->left != NULL)
        q.push(currNode->left);

      if (currNode->right != NULL)
        q.push(currNode->right);

      if (prevNode != NULL)
        prevNode->next = currNode;

      prevNode = currNode;
    }

    if (prevNode != NULL)
      prevNode->next = NULL;
  }
}