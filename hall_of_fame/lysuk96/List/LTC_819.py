'''
Given a string paragraph and a string array of the banned words banned, return the most frequent word that is not banned. It is guaranteed there is at least one word that is not banned, and that the answer is unique.

The words in paragraph are case-insensitive and the answer should be returned in lowercase.

 

Example 1:

Input: paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.", banned = ["hit"]
Output: "ball"
Explanation: 
"hit" occurs 3 times, but it is a banned word.
"ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph. 
Note that words in the paragraph are not case sensitive,
that punctuation is ignored (even if adjacent to words, such as "ball,"), 
and that "hit" isn't the answer even though it occurs more because it is banned.
Example 2:

Input: paragraph = "a.", banned = []
Output: "a"
 

Constraints:

1 <= paragraph.length <= 1000
paragraph consists of English letters, space ' ', or one of the symbols: "!?',;.".
0 <= banned.length <= 100
1 <= banned[i].length <= 10
banned[i] consists of only lowercase English letters.
'''
import collections
from typing import Collection, List
import re
def mostCommonWord(paragraph: str, banned: List[str]) -> str:
    paragraph = paragraph.lower()
    
    remove = "!?',;."
    for i in range(len(remove)):
        paragraph = paragraph.replace(remove[i]," ")

    words = paragraph.split()
    unique = []
    unique_cnt = []
    for data in words:
        if data not in unique and data not in banned:
            unique.append(data)
            unique_cnt.append(words.count(data))
    index = 0
    min = 0
    for i in range (len(unique)):
        if min < unique_cnt[i]:
            index = i
            min = unique_cnt[i]
    return unique[index]

# def mostCommonWord(paragraph: str, banned: List[str]) -> str:
#     words = [word for word in re.sub('[^\w]',' ',paragraph)
#             .lower().split() if word not in banned] #regular expression

#     # 풀이 1 : Dict 사용
#     # counts = collections.defaultdict(int) #이렇게 해야 dict의 초기값으로 0이 들어감
#     # print(counts)
#     # for word in words:
#     #     counts[word]+=1
#     #     print(counts)
#     # print(counts.get)
#     # return max(counts, key=counts.get) #get max key by value

#     # 풀이 2 : Counter 객체 사용
#     counts = collections.Counter(words)
#     return counts.most_common(1)[0][0]


paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
banned = ["hit"]
print(mostCommonWord(paragraph,banned))

# 답지와 비교 :
# 초반에 답지랑 비슷하게 풀었는데, 예외처리 하면서 괜히 다른 알고리즘으로 풀게 됐다 / 
# Counter 객체 사용 필요 or 딕셔너리, 전처리 좀만 하면 람다 표현식으로 간단한 표현 가능

# 걸린 시간 : 38분

# 내 풀이:
# Runtime: 44 ms, faster than 31.21% of Python3 online submissions for Most Common Word.
# Memory Usage: 14.1 MB, less than 97.78% of Python3 online submissions for Most Common Word

# 답지 풀이:
# Runtime: 40 ms, faster than 45.35% of Python3 online submissions for Most Common Word.
# Memory Usage: 14.3 MB, less than 46.25% of Python3 online submissions for Most Common Word.