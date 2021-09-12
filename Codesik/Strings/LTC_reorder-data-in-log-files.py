"""
문제:
    You are given an array of logs. Each log is a space-delimited string of words, where the first word is the identifier.

    There are two types of logs:

    Letter-logs: All words (except the identifier) consist of lowercase English letters.
    Digit-logs: All words (except the identifier) consist of digits.
    Reorder these logs so that:

    The letter-logs come before all digit-logs.
    The letter-logs are sorted lexicographically by their contents. If their contents are the same, then sort them lexicographically by their identifiers.
    The digit-logs maintain their relative ordering.
    Return the final order of the logs.
제한:
    * 1 <= logs.length <= 100
    * 3 <= logs[i].length <= 100
    * All the tokens of logs[i] are separated by a single space.
    * logs[i] is guaranteed to have an identifier and at least one word after the identifier.
입력:
    -
출력:
    -
시작:
    9.13 02:25
소요시간:
    10분
"""

from typing import List


class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        letter = []
        digit = []
        for log in logs:
            if log.split()[1].isdigit():
                digit.append(log)
            else:
                letter.append(log)

        letter.sort(key=lambda x: (x.split()[1:], x.split()[0]))
        return letter + digit
