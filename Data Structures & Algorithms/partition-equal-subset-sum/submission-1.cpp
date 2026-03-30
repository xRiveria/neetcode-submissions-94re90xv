class Solution {
public:
    bool Search(std::vector<int>& nums, int currentIndex, int currentSum, int halfSum)
    {
        if (currentIndex >= nums.size())
        {
            return (currentSum == halfSum); // We never quite got there.
        }

        if (currentSum < 0) return false;

        return Search(nums, currentIndex + 1, currentSum, halfSum) || Search(nums, currentIndex + 1, currentSum + nums[currentIndex], halfSum);
    }

    bool canPartition(vector<int>& nums) {
        // We sum up the total and divide by 2. This is the value we want.
        int totalSum = 0;
        for (auto val : nums)
        {
            totalSum += val;
        }

        if (totalSum % 2 != 0)
        {
            return false;
        }

        int halfSum = totalSum / 2;
        // Now, search.
        return Search(nums, 0, 0, halfSum);
    }
};
