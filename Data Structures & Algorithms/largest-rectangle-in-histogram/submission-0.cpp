class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int largestAreaThusFar = INT_MIN;
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
    }
};
