class Solution {
public:
    std::vector<std::vector<int>> m_Results;
    void DFS(std::vector<int>& values, std::vector<int>& currentValues, int i)
    {
        if (i >= values.size())
        {
            m_Results.push_back(currentValues);
            return;
        }

        currentValues.push_back(values[i]); // Take
        DFS(values, currentValues, i + 1);
        currentValues.pop_back(); // Not Take

        while ((i + 1) < values.size() && values[i] == values[i + 1])
        {
            i++;
        }
        DFS(values, currentValues, i + 1);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<int> currentValues;
        DFS(nums, currentValues, 0);
        return m_Results;
    }
};
