#include <bits/stdc++.h>

class Node

{

public:
    int data;

    Node *next;

    Node(int data)

    {

        this->data = data;

        this->next = NULL;
    }
};

class Queue
{

public:
    Node *head;

    Node *tail;

    Queue()
    {

        head = NULL;

        tail = NULL;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty()
    {

        if (head == NULL)
            return true;

        else
            return false;
    }

    void enqueue(int data)
    {

        Node *newnode = new Node(data);

        if (isEmpty())

        {

            head = newnode;

            tail = newnode;

            return;
        }

        else

        {

            tail->next = newnode;

            tail = newnode;

            return;
        }
    }

    int dequeue()
    {

        if (isEmpty())
            return -1;

        else

        {

            int a = head->data;

            Node *deletenode = head;

            head = head->next;

            delete deletenode;

            return a;
        }
    }

    int front()
    {

        if (isEmpty())
            return -1;

        return head->data;
    }
};
