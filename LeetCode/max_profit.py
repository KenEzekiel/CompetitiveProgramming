from ast import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        diff = 0

        min = prices[0]
        for n in prices:
            if n < min:
                min = n
            diff = max(diff, n - min)
        return diff
        

