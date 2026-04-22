class Solution:
    def reverseBits(self, n: int) -> int:
        r = 0
        for i in range(0, 32):
            bit = 1 & (n >> i)
            r |= bit << (31 - i)

        return r