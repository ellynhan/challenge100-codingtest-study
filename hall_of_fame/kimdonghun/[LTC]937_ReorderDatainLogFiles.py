import sys

class Solution:
    def reorderLogFiles(self, logs: list[str]) -> list[str]:
        letters = []
        digits = []
        
        for i in logs:
            if i.split()[1].isdigit():
                digits.append(i)
            else:
                letters.append(i)
                
        #print(letters)
        #print(digits)
        
        letters = sorted(letters, key = lambda x: (x.split()[1:], x.split()[0]))
        #print(letters)
        
        return letters + digits

s = list(sys.stdin.readline())
sol = Solution()
sol.reorderLogFiles(s)