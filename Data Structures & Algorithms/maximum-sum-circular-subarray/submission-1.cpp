class Solution {
public:
    // Imagine the array is a bracelet. You cut it somewhere, straighten it, and take a chunk from the left and right ends.
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> rightMax(n); // Maximum suffix sum starting at index i or later.
        rightMax[n - 1] = nums[n - 1]; // Last suffix is always itself.
        int suffixSum = nums[n - 1];
        
        // Suffix sum from right.
        // suffixSum will store the maximum suffix sum starting at index i or later.
        for (int i = n - 2; i >= 0; --i)
        {
            suffixSum += nums[i];
            rightMax[i] = std::max(rightMax[i + 1], suffixSum); // suffixSum represents starting at i itself, or anywhere to the right of it.
        }

        int maxSum = INT_MIN;
        int currentMax = 0;
        int prefixSum = 0;

        for (int i = 0; i < n; ++i)
        {
            // Perform Regular Kadanes here in the event our max is in the middle like a normal non-circular question.
            currentMax = std::max(currentMax, 0) + nums[i];
            maxSum = std::max(maxSum, currentMax);
            // Try to find the answer in a circular manner.
            prefixSum += nums[i]; // From Left
            if (i + 1 < n)
            {
                // Any wrapping subarray is alway Prefix + Suffix.
                // For every prefix, attach the best possible suffix that comes after it.
                maxSum = std::max(maxSum, prefixSum + rightMax[i + 1]);
            }
        }

        return maxSum;
    }
};