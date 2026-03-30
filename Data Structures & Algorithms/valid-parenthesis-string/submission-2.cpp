class Solution {
public:
    bool checkValidString(string s) {
        std::stack<int> indexLeftParathesis;
        std::stack<int> indexStarParathesis;

        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(')
            {
                indexLeftParathesis.push(i);
            }
            else if (s[i] == '*')
            {
                indexStarParathesis.push(i);
            }
            else
            {
                if (indexLeftParathesis.size() > 0)
                {
                    indexLeftParathesis.pop();
                }
                else
                {
                    if (indexStarParathesis.size() > 0)
                    {
                        indexStarParathesis.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }

        while (indexLeftParathesis.size() > 0 && indexStarParathesis.size() > 0)
        {
            int topLeftIndex = indexLeftParathesis.top(); indexLeftParathesis.pop();
            if (topLeftIndex > indexStarParathesis.top())
            {
                return false;
            }
            else
            {
                indexStarParathesis.pop();
            }
        }

        return indexLeftParathesis.empty();
    }
};
