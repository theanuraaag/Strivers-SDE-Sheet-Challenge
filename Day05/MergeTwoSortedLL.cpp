#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.

    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int> *sortTwoLists(Node<int> *first, Node<int> *second)
{

    Node<int> *mergedList = nullptr;

    Node<int> *tail = nullptr;

    while (first != nullptr && second != nullptr)

    {

        if (first->data <= second->data)

        {

            if (mergedList == nullptr)

            {

                mergedList = first;

                tail = first;
            }

            else

            {

                tail->next = first;

                tail = tail->next;
            }

            first = first->next;
        }

        else

        {

            if (mergedList == nullptr)

            {

                mergedList = second;

                tail = second;
            }

            else

            {

                tail->next = second;

                tail = tail->next;
            }

            second = second->next;
        }
    }

    if (first != nullptr)

    {

        if (mergedList == nullptr)

        {

            mergedList = first;
        }

        else

        {

            tail->next = first;
        }
    }

    if (second != nullptr)

    {

        if (mergedList == nullptr)

        {

            mergedList = second;
        }

        else

        {

            tail->next = second;
        }
    }

    return mergedList;
}
