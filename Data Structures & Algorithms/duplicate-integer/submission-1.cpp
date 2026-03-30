class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // Alternatively, we can also have nums[i] += nums[i - 1], and obtain the last value.
        // To do the above method, start from index 1, and cache the value at index 0.
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