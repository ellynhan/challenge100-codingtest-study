class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        dic1 = {}
        dic2 = {}

        for i in range(len(s)):
            dic1[s[i]] = dic1.get(s[i], 0) + 1
            dic2[t[i]] = dic2.get(t[i], 0) + 1

        return dic1 == dic2