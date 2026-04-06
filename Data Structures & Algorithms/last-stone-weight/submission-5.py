class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        stones.sort() # Min Heap

        # While there are stones left... 
        while len(stones) > 1:
            biggest = stones.pop()
            secondBiggest = stones.pop()
            remainder = biggest - secondBiggest
            if remainder != 0:
                # find where to put it.
                l = 0
                r = len(stones)
                while (l < r):
                    mid = l + ((r - l) // 2)
                    if remainder < stones[mid]:
                        r = mid
                    else:
                        l = mid + 1
                stones.insert(l, remainder)

        
        if len(stones) == 1:
            return stones[0]
        else:
            return 0