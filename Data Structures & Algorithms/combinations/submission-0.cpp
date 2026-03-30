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

        if (currentValue > n)
        {
            return;
        }

        results.push_back(currentValue);
        DFS(n, k, currentValue + 1, results);
        results.pop_back();
        DFS(n, k, currentValue + 1, results);
    }

    vector<vector<int>> combine(int n, int k) {
        std::vector<int> results;
        DFS(n, k, 1, results);
        return m_Values;
    }
};