class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size() - 1;

        while (i <= j)
        {
            int middleIndex = (i + j) / 2;
            if (nums[middleIndex] == target)
            {
                return middleIndex;
            }

            // If the first index is lesser than the middle index, then we have a sequence of sorted numbers to the left.
            if (nums[i] <= nums[middleIndex])
            {
                if (target > nums[middleIndex] || target < nums[i]) // Target is than 
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
