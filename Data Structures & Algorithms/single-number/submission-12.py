class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        val = 0
        for item in nums:
            val ^= item
        return val
        