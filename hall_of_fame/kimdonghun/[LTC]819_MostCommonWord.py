import collections
import re
import sys

class Solution:
    def mostCommonWord(self, paragraph: str, banned: list[str]) -> str:
        paragraph = re.sub(r'[^\w]', ' ', paragraph)
        str_l = paragraph.lower().split()
        for b_word in banned:
            while b_word in str_l:
                str_l.remove(b_word)
            
        #print(str_l)
        counter = collections.Counter(str_l)
        #print(counter.most_common(1)[0][0])
        return counter.most_common(1)[0][0]


sol = Solution()
sol.mostCommonWord(paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.", banned = ["hit"])