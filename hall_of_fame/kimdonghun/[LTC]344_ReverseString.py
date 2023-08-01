import sys

class Solution:
    def reverseString(self, s: list[str]) -> None:
        print(s.reverse())
        
s = list(sys.stdin.readline())
sol = Solution()
sol.reverseString(s)