import sys

class Solution:
    def isPalindrome(self, s: str) -> bool:
        p_list: Deque = collections.deque()
        
        for i in range(len(s)):
            if s[i].isalnum():
                p_list.append(s[i].lower())

        #print(p_list)

        is_palin = True

        while len(p_list) > 1:
            if p_list.popleft() != p_list.pop():
                return False
            
        return True

s = sys.stdin.readline()
sol = Solution()
print(sol.isPalindrome(s))