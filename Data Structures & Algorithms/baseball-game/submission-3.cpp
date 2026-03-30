class Solution {
public:
    int calPoints(vector<string>& operations) {
        std::stack<int> cache;
        int result = 0;
        for (int i = 0; i < operations.size(); ++i)
        {
            if (operations[i] == "+")
            {
                int top = cache.top(); cache.pop(); // Highest
                int topAgain = cache.top(); cache.pop(); // Second Highest
                cache.push(topAgain); // Put back the second highest first.
                cache.push(top); // Then put back highest.
                cache.push(top + topAgain); // And new one.
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