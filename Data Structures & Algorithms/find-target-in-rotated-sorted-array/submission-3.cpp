class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size() - 1;

        while (i <= j)
        {
            // We will use the middle index at all times.
            int middleIndex = i + ((j - i) / 2);
            if (nums[middleIndex] == target)
            {
                return middleIndex;
            }

            // If the first index is lesser than the middle index, then we have a sequence of sorted numbers to the left.
            if (nums[i] <= nums[middleIndex])
            {
                // 4 5 6 7 0 1 2. Say we want a value bigger than 6.
                // If our target is lesser than 4, then we can skip 4 - 6 directly and just search from index of 6 + 1.
                // Otherwise, if target is greater than 4, we can search from index of 4 to index of 6 - 1.
                if (target > nums[middleIndex] || target < nums[i]) // Means target is lesser than our leftbound, which also implies lesser than our middle index.
                {
                    i = middleIndex + 1;
                }
                else
                {
                    j = middleIndex - 1;
                }
            }
            // If the last index is greater than the middleindex, then we have a sequence of sorted numbers to the right.
            else
            {
                // If our target is lesser than the middle index, or, say we have 4 5 6 7 0 1 2 and we want a value smaller than 6.
                // We check if 6 is larger than the last index at nums[j]. If so, then we can skip index of 6 to the last index and search the left portion.
                // Otherwise, if 6 is lesser than the last index at nums[j], we eliminate everything from the first index to the middle index.
                if (target < nums[middleIndex] || target > nums[j])
                {
                    j = middleIndex - 1;
                }
                else
                {
                    i = middleIndex + 1;
                }
            }
        }

        return -1;
    }
};
