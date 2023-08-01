class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        
        if not s:
            return 0

        start = end = 0 

        ans = 1

        while end < len(s) - 1:
            # print(s[start:end+1])

            if s[end+1] in s[start:end+1]:
                start += 1
                # end += 1
            elif s[end+1] not in s[start:end+1]:
                end += 1

            ans = max(ans, len(s[start:end+1]))
        
        return ans
            


        
        