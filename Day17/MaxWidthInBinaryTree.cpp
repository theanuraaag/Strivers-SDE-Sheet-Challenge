#include <bits/stdc++.h> 


int getMaxWidth(TreeNode<int> *root)

{

    if (!root)

    return 0;

  int ans = 0;

  queue <TreeNode<int> * > q;

  q.push( root);

  while (!q.empty())

   {

    int size = q.size();

    ans=max(ans,size);

 

    for (int i = 0; i < size; i++) {

     TreeNode<int> * temp = q.front();

      q.pop();

     

      if (temp -> left)

        q.push(temp -> left);

      if (temp -> right)

        q.push(temp -> right);

    }

  }

  return ans;

}