class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        s = {}
        for index, item in enumerate(nums):
            if item in s: # If item is found here, we return it as our answer immedietely. 
                return [ s[item], index ]
            else: # Add the complement into the dictionary. We need to find it subsequently.
                s[target - item] = index

        return []

        
        