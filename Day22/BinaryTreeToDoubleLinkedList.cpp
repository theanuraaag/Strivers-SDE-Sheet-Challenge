#include <bits/stdc++.h>

BinaryTreeNode<int> *BTtoDLL(BinaryTreeNode<int> *root)
{

    BinaryTreeNode<int> *head = NULL, *prev = NULL, *cur = root;

    while (cur)
    {

        if (cur->left == NULL)
        {

            if (head == NULL)

                head = cur;

            cur->left = prev;

            if (prev != NULL)

                prev->right = cur;

            prev = cur;

            cur = cur->right;
        }

        else
        {

            BinaryTreeNode<int> *pred = cur->left;

            while (pred->right != NULL && pred->right != cur)

                pred = pred->right;

            if (pred->right == NULL)
            {

                pred->right = cur;

                cur = cur->left;
            }

            else
            {

                cur->left = prev;

                prev = cur;

                cur = cur->right;
            }
        }
    }

    return head;
}