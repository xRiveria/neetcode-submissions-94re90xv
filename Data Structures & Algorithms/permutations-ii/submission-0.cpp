class Solution {
public:
    std::set<std::vector<int>> results;

    void Permute(std::vector<int>& nums, std::vector<int>& result)
    {
        if (result.size() == nums.size())
        {
            results.insert(result);
            return;
        }

        for (auto& num : nums)
        {
            if (num != INT_MIN)
            {
                int val = num;

                result.push_back(num);
                num = INT_MIN;
                Permute(nums, result);
                num = val;
                result.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::vector<int> vals;
        Permute(nums, vals);
        return std::vector<std::vector<int>>(results.begin(), results.end());
    }
};