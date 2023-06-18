/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };


*****************************************************************/

Node *findIntersection(Node *head)
{

    if (head == NULL)
        return NULL;

    Node *slow = head;

    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {

        fast = fast->next->next;

        slow = slow->next;

        if (slow == fast)
        {

            return slow;
        }
    }

    return NULL;
}

Node *firstNode(Node *head)
{

    if (head == NULL)
        return NULL;

    Node *meetPoint = findIntersection(head);

    if (meetPoint == NULL)
    {

        return NULL;
    }

    Node *slow = head; 

    while (slow != meetPoint)
    {

        slow = slow->next;

        meetPoint = meetPoint->next;
    }

    return slow;
}
