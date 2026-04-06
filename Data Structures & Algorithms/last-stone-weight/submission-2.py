class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        # Make every negative. Everything is a min-heap. So smallest in front.
        stones = [-s for s in stones]
        heapq.heapify(stones)

        while len(stones) > 1:
            # Pick the two heaviest stones.
            y = -heapq.heappop(stones) # -8
            x = -heapq.heappop(stones) # -7
            # If both equal, destroy both. 
 
            # X = 8, Y = 7
            # If X < Y, X is gone, and we have new weight Y - X. 
            # [-8, -7, -4, -1, -2, -1]
            if y > x:
                heapq.heappush(stones, -(y - x))

        stones.append(0)
        return abs(stones[0])