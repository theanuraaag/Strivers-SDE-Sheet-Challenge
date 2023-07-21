#include <bits/stdc++.h>
TreeNode<int> *m(vector<int> &p, int &i, int l, int h) {

  if (i == p.size()) {

    return NULL;
  }

  TreeNode<int> *c = NULL;

  if (i < p.size()) {

    c = new TreeNode<int>(p[i]);

    i++;
  }

  if (i < p.size() and p[i] >= l and p[i] < c->data) {

    c->left = m(p, i, l, c->data);
  }

  if (i < p.size() and p[i] >= c->data and p[i] < h) {

    c->right = m(p, i, c->data + 1, h);
  }

  return c;
}

TreeNode<int> *preOrderTree(vector<int> &p) {

  int i = 0;

  return m(p, i, INT_MIN, INT_MAX);
}