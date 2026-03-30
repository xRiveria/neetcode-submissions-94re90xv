class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        std::stack<std::pair<int, int>> values;
        int maxArea = 0;

        for (int i = 0; i < heights.size(); ++i)
        {
            if (i == 0)
            {
                values.push({ i, heights[i] });
                continue;
            }

            std::pair<int, int> currentValue = { i, heights[i] };
            int cachedValue = currentValue.first;
            while (!values.empty() && currentValue.second < values.top().second)
            {
                std::pair<int, int> topValue = values.top();
                values.pop();
                maxArea = std::max(maxArea, (currentValue.first - topValue.first) * topValue.second);
                cachedValue = topValue.first;
            }

            values.push({ cachedValue, currentValue.second });
        }

        while (!values.empty())
        {
            int currentWidth = heights.size() - values.top().first;
            maxArea = std::max(maxArea, currentWidth * values.top().second);
            values.pop();
        }

        return maxArea;

        /*
        int largestAreaThusFar = 0;
        for (int i = 0; i < heights.size(); ++i)
        {
            int currentHeight = heights[i];
            // Find left bound.
            int j = i;
            while (j >= 0)
            {
                if (heights[j] >= heights[i])
                {
                    j--;
                }
                else
                {
                    break;
                }
            }

            // Find right bound.
            int k = i;
            while (k < heights.size())
            {
                if (heights[k] >= heights[i])
                {
                    k++;
                }
                else
                {
                    break;
                }
            }
            
            j++;
            k--;
            largestAreaThusFar = std::max(largestAreaThusFar, heights[i] * ((k - j) + 1));
        }

        return largestAreaThusFar;
        */
    }
};
