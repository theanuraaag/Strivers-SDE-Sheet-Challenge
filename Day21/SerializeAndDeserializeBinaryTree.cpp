string serializeTree(TreeNode<int> *root) {
  if (!root) {
    return "#";
  }
  string ans = to_string(root->data) + ",";
  string l = serializeTree(root->left);
  string r = serializeTree(root->right);
  return ans + l + r;
}
TreeNode<int> *helper(string &serialized, int &index) {
  if (index >= serialized.length() || serialized[index] == '#') {
    index++;
    return NULL;
  }
  int num = 0;
  while (index < serialized.length() && serialized[index] >= '0' &&
         serialized[index] <= '9') {
    num = (num * 10) + (serialized[index] - '0');
    index++;
  }
  TreeNode<int> *root = new TreeNode<int>(num);
  index++;
  root->left = helper(serialized, index);
  root->right = helper(serialized, index);
  return root;
}
TreeNode<int> *deserializeTree(string &serialized) {
  int index = 0;
  return helper(serialized, index);
}
