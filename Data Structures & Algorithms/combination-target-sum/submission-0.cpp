class Solution {
public:
    std::vector<std::vector<int>> m_Results;

    void DFS(std::vector<int>& nums, std::vector<int>& currentResults, int i, int remaining)
    {
        if (remaining == 0)
        {
            m_Results.push_back(currentResults);
            return;
        }

        if (remaining < 0 || i >= nums.size())
        {
            return;
        }

        currentResults.push_back(nums[i]);
        DFS(nums, currentResults, i, remaining - nums[i]);
        currentResults.pop_back();
        DFS(nums, currentResults, i + 1, remaining);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        std::vector<int> currentResults;
        DFS(nums, currentResults, 0, target);
        return m_Results;
    }
};
