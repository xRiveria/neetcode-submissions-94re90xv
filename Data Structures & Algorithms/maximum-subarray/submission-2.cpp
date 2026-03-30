class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        int l = 0;
        int r = 0;

        int maxValueThusFar = INT_MIN;
        int currentValues = 0;
        while (l < nums.size())
        {
            currentValues += nums[r];
            maxValueThusFar = std::max(maxValueThusFar, currentValues);
            if (currentValues < 0)
            {
                l += 1;
                r = l;
                currentValues = 0;
                continue;
            }
            else
            {
                r++;

                if (r >= nums.size())
                {
                    l += 1;
                    r = l;
                    currentValues = 0;
                }
            }
        }

        return maxValueThusFar;
    }
};
