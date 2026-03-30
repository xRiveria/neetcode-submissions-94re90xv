class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<std::vector<int>> results = {{}};

        for (int i = 0; i < nums.size(); ++i)
        {
            int size = results.size();
            for (int j = 0; j < size; ++j)
            {
                std::vector<int> subset = results[j];
                subset.push_back(nums[i]);
                results.push_back(subset);
            }
        }

        return results;
    }
};
