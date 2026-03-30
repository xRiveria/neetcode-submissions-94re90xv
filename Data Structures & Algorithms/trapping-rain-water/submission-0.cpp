class Solution {
public:
    int trap(vector<int>& height) {
        std::vector<int> leftAccumulatedWater(height.size());
        std::vector<int> rightAccumulatedWater(height.size());
        std::vector<int> leftRightMinimumWater(height.size());

        // Left Pass
        for (int i = 0; i < height.size(); ++i)
        {
             if (i == 0)
             {
                leftAccumulatedWater[i] = height[i];
                continue;
             }
             
             // Either we take the previous one, or the max thus far. 
             leftAccumulatedWater[i] = std::max(leftAccumulatedWater[i - 1], height[i]);
        }
        
        for (int i = height.size() - 1; i >= 0; --i)
        {
             if (i == height.size() - 1)
             {
                rightAccumulatedWater[i] = height[i];
                continue;
             }
             
             // Finally update the max thus far.
             rightAccumulatedWater[i] = std::max(rightAccumulatedWater[i + 1], height[i]);
        }

        int maxVolume = 0;
        for (int i = 0; i < height.size(); ++i)
        {
            maxVolume += (std::min(leftAccumulatedWater[i], rightAccumulatedWater[i]) - height[i]);
        }

        return maxVolume;
    }
};
