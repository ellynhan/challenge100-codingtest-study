"""
문제:
    Given an array of strings strs, group the anagrams together. You can return the answer in any order.
    An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
제한:
    * 1 <= strs.length <= 104
    * 0 <= strs[i].length <= 100
    * strs[i] consists of lowercase English letters.
입력:
    -
출력:
    -
시작:
    9.13 03:10
소요시간:
    30분
"""
from typing import List


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        words = [("".join(sorted(list(word), key=lambda x: x[0])), word)
                 for word in strs]
        words = sorted(words, key=lambda x: x[0])

        words_dict = dict()

        for word in words:
            try:
                words_dict[word[0]].append(word[1])
            except KeyError:
                words_dict[word[0]] = []
                words_dict[word[0]].append(word[1])
        answer = list(words_dict.values())
        answer.sort(key=len)
        return answer
