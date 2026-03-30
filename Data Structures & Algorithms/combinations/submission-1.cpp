class Solution {
public:
    std::vector<std::vector<int>> m_Values;

    void DFS(int n, int k, int currentValue, std::vector<int>& results)
    {
        if (results.size() == k)
        {
            m_Values.push_back(results);
            return;
        }

        for (int i = currentValue; i <= n; ++i)
        {
            results.push_back(i);
            DFS(n, k, i + 1, results);
            results.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        std::vector<int> results;
        DFS(n, k, 1, results);
        return m_Values;
    }
};