class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        dups = set()
        for item in nums:
            if item in dups:
                return True
            dups.add(item)

        return False;
            