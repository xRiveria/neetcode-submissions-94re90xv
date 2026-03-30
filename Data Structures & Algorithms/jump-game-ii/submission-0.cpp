class Solution {
public:
    int m_MinCount = INT_MAX;
    void DFS(std::vector<int>& values, int i, int jumpCount)
    {
        if (i >= values.size())
        {
            return;
        }

        if (i == values.size() - 1)
        {
            m_MinCount = std::min(m_MinCount, jumpCount);
            return;
        }

        for (int j = 1; j <= values[i]; ++j)
        {
            DFS(values, i + j, jumpCount + 1);
        }
    }

    int jump(vector<int>& nums) {
        DFS(nums, 0, 0);
        return m_MinCount;
    }
};
