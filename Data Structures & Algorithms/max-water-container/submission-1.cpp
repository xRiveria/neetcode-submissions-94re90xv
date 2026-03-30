class Solution {
public:
    int maxArea(vector<int>& heights) {
       
        int i = 0;
        int j = heights.size() - 1;
        int maximumWaterThusFar = INT_MIN;
        while (i < j)
        {
            int maximumWidth = j - i;
            int maximumHeight = std::min(heights[i], heights[j]);
            int currentWater = maximumWidth * maximumHeight;
            maximumWaterThusFar = std::max(maximumWaterThusFar, currentWater);
            
            if (heights[i] < heights[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        
        return maximumWaterThusFar;
    }
};
