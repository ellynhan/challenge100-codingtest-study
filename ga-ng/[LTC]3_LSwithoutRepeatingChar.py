class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        
        right = left = max_len = 0
        d = {}

        while right < len(s):
            if not s[right] in d:
                d[s[right]] = 1

            else:
                d[s[right]] += 1      ## a 2 b 1 c 1  ## right = 3 이고 , a
                if d[s[right]] > 1:
                    while d[s[right]] > 1:
                        d[s[left]] -= 1
                        left += 1

            max_len = max(max_len, right - left + 1)
            right += 1
        return max_len