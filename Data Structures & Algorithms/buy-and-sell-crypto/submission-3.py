class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        profit = 0
        smallestPrice = math.inf

        for item in prices:
            if item < smallestPrice:
                smallestPrice = item
            else:
                profit = max(profit, item - smallestPrice)
                
        return profit 