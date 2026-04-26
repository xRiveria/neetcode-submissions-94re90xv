class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        row = [1] * n # The previous row.

        for i in range(m - 1):
            newRow = [1] * n # The current row.
            for j in range(n - 2, -1, -1):
                newRow[j] = newRow[j + 1] + row[j]
            row = newRow
        return row[0]