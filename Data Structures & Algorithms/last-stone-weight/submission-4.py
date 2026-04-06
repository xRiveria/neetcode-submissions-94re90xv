class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        stones.sort() # Min Heap
        n = len(stones)

        # While there are stones left... 
        while n > 1:
            biggest = stones.pop()
            secondBiggest = stones.pop()
            n -= 2
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
                pos = l
                n += 1
                stones.append(0)
                for i in range(n - 1, pos, -1):
                    stones[i] = stones[i - 1]
                stones[pos] = remainder

        
        if len(stones) == 1:
            return stones[0]
        else:
            return 0