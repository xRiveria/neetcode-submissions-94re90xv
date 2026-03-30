class Solution {
public:
    std::vector<int> twoSum(vector<int>& nums, int target) 
    {
        std::unordered_map<int, int> values;
        for (int i = 0; i < nums.size(); ++i)
        {
            int value = target - nums[i];
            if (values.count(value))
            {
                // Since we're iterating from index 0, any complements found is guaranteed to be at a lower index. All good.
                return { values[value], i }; 
            }

            values[nums[i]] = i;
        }

        // Answer answer is guaranteed to exist.
        return {};
    }
};
