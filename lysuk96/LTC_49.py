'''
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.
'''
from typing import  List
import collections

def groupAnagrams(strs: List[str]) -> List[List[str]]:
    sort = [sorted(word) for word in strs]
    words = collections.defaultdict(list)
    for index, value in enumerate(sort):
        word = ''
        for i in range(len(value)):
            word += value[i]
        words[word].append(index)

    ans =[]
    for key in words:
        tmp = [strs[index] for index in words[key]]
        ans += [tmp]
    return ans

strs = ["eat","tea","tan","ate","nat","bat"]
print(groupAnagrams(strs))

# 답지와 비교 :
# 정렬하여 dict에 추가하는 부분을 한문장으로 줄일 수 있다.

# 걸린 시간 : 30분

# 내 풀이:
# Runtime: 141 ms, faster than 28.16% of Python3 online submissions for Group Anagrams.
# Memory Usage: 20 MB, less than 8.05% of Python3 online submissions for Group Anagrams.


# 답지 풀이: