class Solution {
public:
    std::vector<int> m_Cache;
    int DFS(int n, int i)
    {
        if (i >= n) return i == n; // 1 if true.
        if (m_Cache[i] != -1) return m_Cache[i];
        m_Cache[i] = DFS(n, i + 1) + DFS(n, i + 2);
        return m_Cache[i];
    }

    int climbStairs(int n) {
        m_Cache.resize(n, -1);
        return DFS(n, 0);
    }
};
