class Solution {
public:
    bool isValid(string s) {
        std::stack<char> values;
        for (char c : s)
        {
            if (c == '{' || c == '(' || c == '[')
            {
                values.push(c);
            }
            else
            {
                if (!values.empty() && (c == '}' || c == ']' || c == ')'))
                {
                    if (c == '}' && values.top() == '{')
                    {
                        values.pop();
                    }
                    else if (c == ']' && values.top() == '[')
                    {
                        values.pop();
                    }
                    else if (c == ')' && values.top() == '(')
                    {
                        values.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
        }

        if (!values.empty())
        {
            return false;
        }

        return true;
    }
};
