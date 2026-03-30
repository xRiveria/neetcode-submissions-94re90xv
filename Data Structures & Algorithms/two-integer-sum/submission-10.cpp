class Solution {
public:
    std::vector<int> twoSum(vector<int>& nums, int target) 
    {
        std::vector<std::pair<int, int>> values;
        for (int i = 0; i < nums.size(); ++i)
        {
            values.push_back({ nums[i], i });
        }

        std::sort(values.begin(), values.end());

        int i = 0, j = values.size() - 1;
        while (i < j)
        {
            int currentSum = values[i].first + values[j].first;
            if (currentSum == target)
            {
                if (values[i].second > values[j].second)
                {
                    return { values[j].second, values[i].second };
                }
                
                return { values[i].second, values[j].second };
            }
            else if (currentSum > target)
            {
                j--;
            }
            else
            {
                i++;
            }
        }

        return {};

        // HashMap (One Pass) Solution
        // std::unordered_map<int, int> values;
        // for (int i = 0; i < nums.size(); ++i)
        // {
        //     int value = target - nums[i];
        //     if (values.count(value))
        //     {
        //         // Since we're iterating from index 0, any complements found is guaranteed to be at a lower index. All good.
        //         return { values[value], i }; 
        //     }

        //     values[nums[i]] = i;
        // }

        // // Answer answer is guaranteed to exist.
        // return {};
    }
};
