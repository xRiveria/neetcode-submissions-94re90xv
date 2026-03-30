class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r)
        {
            int midIndex = l + ((r - l) / 2);
            if (nums[midIndex] == target)
            {
                return midIndex;
            }
            
            if (nums[midIndex] > target)
            {
                r = midIndex - 1;
            }
            else
            {
                l = midIndex + 1;
            }
        }

        return -1;
    }
};
