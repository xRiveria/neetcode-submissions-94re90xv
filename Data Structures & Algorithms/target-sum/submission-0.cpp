class Solution {
public:
    int m_DiffWays = 0;

    void DFS(std::vector<int>& values, int target, int currentSum, int currentIndex)
    {
        if (currentIndex >= values.size())
        {
            if (currentSum == target)
            {
                m_DiffWays++;
            }
            return;
        }

        DFS(values, target, currentSum + values[currentIndex], currentIndex + 1);
        DFS(values, target, currentSum - values[currentIndex], currentIndex + 1);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        DFS(nums, target, 0, 0);
        return m_DiffWays;
    }
};
