class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        leMap = {}
        def DFS(i, j):
            if (i, j) in leMap:
                return leMap[(i, j)]

            if i >= m or j >= n:
                return 0
            
            if i == m - 1 and j == n - 1:
                return 1 

            totalWays = 0
            totalWays += DFS(i + 1, j)
            totalWays += DFS(i, j + 1)

            leMap[(i, j)] = totalWays
            return totalWays
        return DFS(0, 0)
        