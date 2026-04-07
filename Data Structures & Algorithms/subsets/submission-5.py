class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        result = []
        subset = []

        def dfs(i):
            if i >= len(nums):
                result.append(subset.copy())
                return
            subset.append(nums[i])
            dfs(i + 1) # Go do [1, 2, 3] first. Pop (backtrack), etc.
            subset.pop()
            dfs(i + 1)

        dfs(0)
        return result