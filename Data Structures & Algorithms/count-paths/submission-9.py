class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        leMap = [[-1] * n for _ in range(m)]
        def DFS(i, j):
            if i >= m or j >= n:
                return 0
            
            if i == m - 1 and j == n - 1:
                return 1 

            if leMap[i][j] != -1:
                return leMap[i][j]

            leMap[i][j] = DFS(i + 1, j) + DFS(i, j + 1)
            return leMap[i][j]
        return DFS(0, 0)
        