class Solution:
    def hammingWeight(self, n: int) -> int:
        bit = []

        while n != 0:
            bit.append(n % 2)
            n //= 2

        bit.reverse()
        # print(bit.count(1))

        # if len(bit) < 32:
        return bit.count(1)
