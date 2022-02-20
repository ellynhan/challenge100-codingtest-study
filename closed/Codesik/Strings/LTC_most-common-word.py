"""
문제:
    Given a string paragraph and a string array of the banned words banned, return the most frequent word that is not banned.
    It is guaranteed there is at least one word that is not banned, and that the answer is unique.

    The words in paragraph are case-insensitive and the answer should be returned in lowercase.
제한:
    * 1 <= paragraph.length <= 1000
    * paragraph consists of English letters, space ' ', or one of the symbols: "!?',;.".
    * 0 <= banned.length <= 100
    * 1 <= banned[i].length <= 10
    * banned[i] consists of only lowercase English letters.
입력:
    -
출력:
    -
시작:
    9.13 02:50
소요시간:
    10분
"""

import collections
import re
from typing import List


class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        words = [word for word in re.sub('[^\w]', ' ', paragraph).lower().split() if word not in banned]
        return collections.Counter(words).most_common(1)[0][0]

