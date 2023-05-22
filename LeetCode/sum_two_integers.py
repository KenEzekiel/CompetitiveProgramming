class Solution:
    def getSum(self, a: int, b: int) -> int:
        # No carry
        while b != 0:

            temp = (a & b) << 1
            # print(bin(temp), bin(b))
            a = a ^ b
            # print(bin(a))
            # Check for carry bit
            b = temp
            # print(bin(b))

        # print("\n", bin(a))
        return a

sol = Solution()
print(sol.getSum(-1,1))
