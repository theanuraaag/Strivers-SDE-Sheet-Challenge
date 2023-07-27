#include <bits/stdc++.h>

struct Node
{

    int prefix = 0;

    int complete = 0;

    Node *arr[26];
};

class Trie
{

    Node *root;

public:
    Trie()
    {

        root = new Node();
    }

    void insert(string &s)
    {

        int n = s.length();

        Node *temp = root;

        for (int i = 0; i < n; i++)
        {

            if (temp->arr[s[i] - 'a'] == NULL)
                temp->arr[s[i] - 'a'] = new Node();

            temp = temp->arr[s[i] - 'a'];

            temp->prefix++;
        }

        temp->complete++;
    }

    int countWordsEqualTo(string &s)
    {

        int n = s.length();

        Node *temp = root;

        for (int i = 0; i < n; i++)
        {

            if (temp->arr[s[i] - 'a'] == NULL)
                return 0;

            temp = temp->arr[s[i] - 'a'];
        }

        return temp->complete;
    }

    int countWordsStartingWith(string &s)
    {

        int n = s.length();

        Node *temp = root;

        for (int i = 0; i < n; i++)
        {

            if (temp->arr[s[i] - 'a'] == NULL)
                return 0;

            temp = temp->arr[s[i] - 'a'];
        }

        return temp->prefix;
    }

    void erase(string &s)
    {

        int n = s.length();

        Node *temp = root;

        for (int i = 0; i < n; i++)
        {

            temp = temp->arr[s[i] - 'a'];

            temp->prefix--;
        }

        temp->complete--;
    }
};