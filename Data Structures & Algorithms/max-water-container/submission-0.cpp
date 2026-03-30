class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maximumWaterThusFar = INT_MIN;
        for (int i = 0; i < heights.size(); ++i)
        {
            int j = i + 1;
            while (j <= heights.size() - 1)
            {
                int maximumWidth = j - i;
                int maximumHeight = std::min(heights[i], heights[j]);
                int currentWater = maximumWidth * maximumHeight;
                maximumWaterThusFar = std::max(maximumWaterThusFar, currentWater);
                j++;
            }
        }
        
        return maximumWaterThusFar; 
    }
};
