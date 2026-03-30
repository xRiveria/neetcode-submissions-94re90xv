class Solution {
public:
    std::vector<std::vector<int>> results;
    void DFS(std::vector<int>& values, int i, std::vector<int>& subsets)
    {
        if (i >= values.size())
        {
            results.push_back(subsets);
            return;
        }

        // Include
        std::vector<int> copy = subsets;
        copy.push_back(values[i]);
        DFS(values, i + 1, copy); // Include the number.

        // Not Include
        DFS(values, i + 1, subsets); // Don't include. 
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<int> subsets;
        DFS(nums, 0, subsets);
        return results;
    }
};
