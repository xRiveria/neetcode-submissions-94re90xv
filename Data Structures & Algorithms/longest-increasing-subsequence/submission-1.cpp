class Solution {
public:
    int m_MaxSequenceCount = INT_MIN;
    void LongestSubsequence(std::vector<int>& nums, int i, int currentSequenceCount, int lastIncludedValue)
    {
        if (i >= nums.size())
        {
            m_MaxSequenceCount = std::max(m_MaxSequenceCount, currentSequenceCount);
            return;
        }

        // Before including, we need to make sure that it is absolutely greater than the previous element.
        // If not, the sequence is invalid. Return currentSequenceCount.
        if (i == 0)
        {
            // Always include the first one.
            LongestSubsequence(nums, i + 1, currentSequenceCount + 1, nums[i]); // Include
        }
        else if (i > 0 && nums[i] > lastIncludedValue) // If second onwards, ensure its larger than the previous one.
        {
            LongestSubsequence(nums, i + 1, currentSequenceCount + 1, nums[i]); // Include
        }

        LongestSubsequence(nums, i + 1, currentSequenceCount, lastIncludedValue); // Don't include. 
    }

    int lengthOfLIS(vector<int>& nums) {
        LongestSubsequence(nums, 0, 0, 0);
        return m_MaxSequenceCount;
    }
};
