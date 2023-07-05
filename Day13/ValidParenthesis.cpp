bool isValidParenthesis(string expression)

{

    // Write your code here.

    stack<char> s;

    for (char ch : expression)
    {

        if (ch == '(' || ch == '{' || ch == '[')
        {

            s.push(ch);
        }

        else
        {

            if (s.empty())
            {

                return false;
            }

            if (s.top() == '(' && ch == ')')
            {

                s.pop();
            }
            else if (s.top() == '{' && ch == '}')
            {

                s.pop();
            }
            else if (s.top() == '[' && ch == ']')
            {

                s.pop();
            }
            else
            {

                return false;
            }
        }
    }

    return s.empty();
}