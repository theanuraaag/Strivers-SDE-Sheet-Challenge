/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

int length(Node *head)
{

    int c = 0;

    while (head != NULL)
    {

        c++;

        head = head->next;
    }

    return c;
}

Node *rotate(Node *head, int k)
{

    // Write your code here.

    int n = length(head);

    if (k == 0 || n == 0)
        return head;

    k = k % n;

    k = n - k;

    Node *temp = head;

    while (temp->next)
    {

        temp = temp->next;
    }

    temp->next = head;

    while (k--)
    {

        temp = temp->next;
    }

    head = temp->next;

    temp->next = NULL;

    return head;
}