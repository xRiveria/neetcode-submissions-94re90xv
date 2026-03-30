class Solution {
public:
    int m_UniqueWays = 0;
    std::vector<std::vector<int>> m_Cache;

    int DFS(int m, int n, int i, int j)
    {
        if (i < 0 || j < 0 || i >= m || j >= n)
        {
            return 0;
        }

        if (m_Cache[i][j] != -1)
        {
            return m_Cache[i][j];
        }

        if (i == (m - 1) && j == (n - 1))
        {
            m_Cache[i][j] = 1;
            return 1;
        }

        m_UniqueWays += DFS(m, n, i + 1, j);
        m_UniqueWays += DFS(m, n, i, j + 1);

        return 0; 
    }

    int uniquePaths(int m, int n) {
        if (m == 1 && n == 1)
        {
            return 1;
        }

        m_Cache.resize(m, std::vector<int>(n, -1));
        DFS(m, n, 0, 0);
        return m_UniqueWays;
    }
};
