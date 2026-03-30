class Solution {
public:
    int calPoints(vector<string>& operations) {
        std::stack<int> cache;
        for (int i = 0; i < operations.size(); ++i)
        {
            if (operations[i] == "+")
            {
                int top = cache.top(); cache.pop();
                int topAgain = cache.top(); cache.pop();
                cache.push(topAgain);
                cache.push(top);
                cache.push(top + topAgain);
            }
            else if (operations[i] == "D")
            {
                int top = cache.top();
                cache.push(top * 2);
            }
            else if (operations[i] == "C")
            {
                cache.pop();
            }
            else
            {
                cache.push(std::stoi(operations[i]));
            }
        }

        int result = 0;
        while (!cache.empty())
        {
            result += cache.top(); cache.pop();
        }
        return result;
    }
};