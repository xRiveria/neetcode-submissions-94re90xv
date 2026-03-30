class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minElementCount = INT_MAX;
        int currentSum = 0;
        int l = 0;
        int r = l;

        while (r < nums.size())
        {
            currentSum += nums[r];
            if (currentSum >= target)
            {
                while (currentSum >= target)
                {
                    minElementCount = std::min(minElementCount, r - l + 1);
                    currentSum -= nums[l];
                    l++;
                }
            }
            r++;
        }

        if (minElementCount == INT_MAX) return 0;
        return minElementCount; 
    }
};