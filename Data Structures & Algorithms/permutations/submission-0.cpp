class Solution {
public:
    std::vector<std::vector<int>> results;
    void DFS(std::vector<int>& values, std::vector<bool>& pickList, std::vector<int>& currentResults)
    {
        if (currentResults.size() == values.size())
        {
            results.push_back(currentResults);
            return;
        }

        for (int i = 0; i < pickList.size(); ++i)
        {
            if (!pickList[i])
            {
                currentResults.push_back(values[i]);
                pickList[i] = true;
                DFS(values, pickList, currentResults);
                currentResults.pop_back();
                pickList[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        std::vector<bool> pickList(nums.size());
        std::vector<int> currentResults;
        DFS(nums, pickList, currentResults);
        return results;
    }
};
