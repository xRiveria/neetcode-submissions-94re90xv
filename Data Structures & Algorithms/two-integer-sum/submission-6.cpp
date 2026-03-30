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
                return { values[value], i };
            }

            values[nums[i]] = i;
        }

        // Answer answer is guaranteed to exist.
        return {};
    }
};
