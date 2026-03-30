class Solution {
public:
    int calPoints(vector<string>& operations) {
        std::stack<int> cache;
        int result = 0;
        for (int i = 0; i < operations.size(); ++i)
        {
            if (operations[i] == "+")
            {
                int top = cache.top(); cache.pop();
                int topAgain = cache.top(); cache.pop();
                cache.push(topAgain);
                cache.push(top);
                cache.push(top + topAgain);
                result += (top + topAgain);
            }
            else if (operations[i] == "D")
            {
                int top = cache.top();
                cache.push(top * 2);
                result += (top * 2);
            }
            else if (operations[i] == "C")
            {
                result -= cache.top();
                cache.pop();
            }
            else
            {
                cache.push(std::stoi(operations[i]));
                result += std::stoi(operations[i]);
            }
        }

        
        return result;
    }
};