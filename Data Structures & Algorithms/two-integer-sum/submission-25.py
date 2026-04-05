from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        du = [(num, idx) for idx, num in enumerate(nums)]
        du.sort()
        
        i = 0
        j = len(du) - 1
        
        while i < j:
            z = du[i][0] + du[j][0]
            if z == target:
                return [min(du[i][1], du[j][1]), max(du[i][1], du[j][1])]
            elif z > target:
                j -= 1
            else:
                i += 1
        
        return []
        
        