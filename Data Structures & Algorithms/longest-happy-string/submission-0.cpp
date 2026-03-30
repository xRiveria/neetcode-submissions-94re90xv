class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        // Place the most frequent.
        // Place the second most frequent.
        // Place the last most frequent. 
        // Cannot be aaa, bbb or ccc.
        std::string happyString = "";
        // Create a binary heap. 
        // Track last created. Cannot use again. 
        std::priority_queue<std::pair<int, char>> values;
        if (a > 0) values.push({ a, 'a' });
        if (b > 0) values.push({ b, 'b' });
        if (c > 0) values.push({ c, 'c' });

        while (!values.empty())
        {
            std::pair<int, char> topValue = values.top(); values.pop();
            
            // Cannot reuse the current one.. 
            if (happyString.length() >= 2 && happyString[happyString.size() - 1] == topValue.second && happyString[happyString.size() - 2] == topValue.second)
            {
                if (values.empty())
                {
                    break; // There is no alternative. We're done.
                }

                std::pair<int, char> secondValue = values.top(); values.pop();
                happyString += secondValue.second;
                secondValue.first--;
                if (secondValue.first > 0) values.push(secondValue);
                // Put back the first value since we didn't use it.
                values.push(topValue);
            }
            else
            {
                happyString += topValue.second;
                topValue.first--;
                if (topValue.first > 0) values.push(topValue);
            }
        }

        return happyString;
    }
};