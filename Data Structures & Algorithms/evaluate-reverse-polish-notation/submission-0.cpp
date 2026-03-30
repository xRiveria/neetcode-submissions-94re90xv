class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> values;
        for (int i = 0; i < tokens.size(); ++i)
        {
            std::istringstream iss(tokens[i]);
            int value;
            if (!(iss >> value))
            {
                // Finish Operation
                // Push back into stack.
                int secondDigit = values.top(); values.pop();
                int firstDigit = values.top(); values.pop();
                if (tokens[i] == "+")
                {
                    values.push(firstDigit + secondDigit);
                }
                else if (tokens[i] == "-")
                {
                    values.push(firstDigit - secondDigit);
                }
                else if (tokens[i] == "*")
                {
                    values.push(firstDigit * secondDigit);
                }
                else if (tokens[i] == "/")
                {
                    values.push(firstDigit / secondDigit);
                }
            }
            else
            {
                values.push(std::stoi(tokens[i]));
            }
        }

        return values.top();
    }
};
