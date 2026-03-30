class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i)
        {
            int index = std::abs(nums[i]) - 1;
            if (nums[index] < 0)
            {
                return std::abs(nums[i]);
            }
            nums[index] *= -1;
        }

        return true;
    }
};
