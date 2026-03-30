class Solution {
public:
    // Set makes sure we get no duplicate values. A good way to solve if we don't use a while loop.
    std::vector<std::vector<int>> results;
    void DFS(std::vector<int>& candidates, int target, int i, std::vector<int>& currentResults, int total)
    {
        if (total == target)
        {
            results.push_back(currentResults);
            return;
        }

        if (total > target || i >= candidates.size())
        {
            return;
        }

        currentResults.push_back(candidates[i]);
        DFS(candidates, target, i + 1, currentResults, total + candidates[i]);
        currentResults.pop_back();

        while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1])
        {
            i++;
        }

        DFS(candidates, target, i + 1, currentResults, total);
    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<int> currentResults;
        DFS(candidates, target, 0, currentResults, 0);
        return results;
    }
};
