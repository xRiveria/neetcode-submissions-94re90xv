class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        start = [ [] ]
        for number in nums:
            for item in start[:]:
                newList = list(item)
                newList.append(number)
                start.append(newList)

        return start