#include <bits/stdc++.h>
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int> *rev(LinkedListNode<int> *head)

{

    LinkedListNode<int> *prev = NULL;

    LinkedListNode<int> *cur = head;

    while (cur != NULL)

    {

        LinkedListNode<int> *nxt = cur->next;

        cur->next = prev;

        prev = cur;

        cur = nxt;
    }

    head = prev;

    return head;
}

LinkedListNode<int> *middle(LinkedListNode<int> *head)

{

    if (head == NULL)
        return NULL;

    LinkedListNode<int> *cur = head;

    int nodes = 0;

    while (cur != NULL)

    {

        nodes++;

        cur = cur->next;
    }

    cur = head;

    int th = nodes / 2;

    while (th)

    {

        th--;

        cur = cur->next;
    }

    return cur;
}

bool isPalindrome(LinkedListNode<int> *head)
{

    if (head == NULL or head->next == NULL)
        return true;

    LinkedListNode<int> *mid = middle(head);

    LinkedListNode<int> *h1 = rev(mid);

    LinkedListNode<int> *c1 = h1;

    LinkedListNode<int> *c2 = head;

    while (c1 != mid->next)

    {

        if (c1->data != c2->data)
            return false;

        c1 = c1->next;

        c2 = c2->next;
    }

    return true;
}