class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> results = {{}};
        int previousIndex = 0;
        int index = 0; // Determines where to start extending subsets.
        // To avoid duplicate subsets, when you see a duplicate number, you only add it to the subsets you just created — not all of them.
        // Aka subsets created in the previous step only. Hence previousIndex.
        for (int i = 0; i < nums.size(); ++i)
        {
            index = (i >= 1 && nums[i] == nums[i - 1]) ? previousIndex : 0;
            previousIndex = results.size();

            // Create new subsets by adding to existing ones.
            for (int j = index; j < previousIndex; ++j)
            {
                std::vector<int> temp = results[j];
                temp.push_back(nums[i]);
                results.push_back(temp);
            }
        }

        return results;
    }
};
