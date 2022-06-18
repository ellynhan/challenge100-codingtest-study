class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        i = 0
        j = 0
        while True:
            if i == len(s) or j == len(t):
                if i == len(s):
                    return True
                return False
            if s[i] == t[j]:
                i += 1
            j += 1
