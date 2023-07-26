class Solution:
    def reverseBits(self, n: int) -> int:
        num1 = n
        ans = cnt = 0
        while num1:
            ans = ans * 2 + num1 % 2
            num1 //= 2
            cnt += 1

        while cnt < 32:
            ans *= 2
            cnt += 1

        return ans