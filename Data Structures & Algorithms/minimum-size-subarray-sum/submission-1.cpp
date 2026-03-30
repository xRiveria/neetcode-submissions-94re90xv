class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        // prefixSum[i] stores the sum of the first i elements.
        std::vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i)
        {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        int result = n + 1;
        // For each index i, we ask...
        for (int i = 0; i < n; ++i)
        {
            // What is the shortest subarray starting at i whose sum is ≥ target?
            int l = i, r = n;
            // Instead of checking all possible endings, it uses binary search to quickly find the first position where the sum becomes big enough.
            while (l < r)
            {
                int mid = (l + r) / 2;
                // Sum of elements from index i to mid. 
                int currentSum = prefixSum[mid + 1] - prefixSum[i];
                // Once the sum becomes ≥ target, it stays ≥ target for all larger j.
                if (currentSum >= target)
                {
                    r = mid; // try shorter window
                }
                else
                {
                    l = mid + 1; // need larger window
                }
            }

            // It keeps track of the smallest valid window found.
            if (l != n)
            {
                result = min(result, l - i + 1);
            }
        }

        return result % (n + 1);
    }
};