class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> values;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (values.count(nums[i]))
            {
                return true;
            }

            values.insert(nums[i]);
        }

        return false;
    }
};