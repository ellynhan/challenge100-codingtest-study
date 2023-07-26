'''
You are given an array of logs. Each log is a space-delimited string of words, where the first word is the identifier.

There are two types of logs:

Letter-logs: All words (except the identifier) consist of lowercase English letters.
Digit-logs: All words (except the identifier) consist of digits.
Reorder these logs so that:

The letter-logs come before all digit-logs.
The letter-logs are sorted lexicographically by their contents. If their contents are the same, then sort them lexicographically by their identifiers.
The digit-logs maintain their relative ordering.
Return the final order of the logs.

 

Example 1:

Input: logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
Output: ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]
Explanation:
The letter-log contents are all different, so their ordering is "art can", "art zero", "own kit dig".
The digit-logs have a relative order of "dig1 8 1 5 1", "dig2 3 6".
Example 2:

Input: logs = ["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]
Output: ["g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 4 7"]
 

Constraints:

1 <= logs.length <= 100
3 <= logs[i].length <= 100
All the tokens of logs[i] are separated by a single space.
logs[i] is guaranteed to have an identifier and at least one word after the identifier.
'''
from typing import List

def reorderLogFiles(logs: List[str]) -> List[str]:
    let =[]
    dig =[]
    for data in logs:
        if data.split(" ")[1].isnumeric():
            dig.append(data)
        else :
            let.append(data)
    print(dig,let)
    ans = sorted(let, key= lambda x : x.split(" ")[0:])
    ans = sorted(ans, key= lambda x : x.split(" ")[1:])
    ans += dig
    return ans

logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let4 art zero","let3 art zero"]
logs = ["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]
print(reorderLogFiles(logs))

# 주의 : 문제 예제 제대로 확인 후 넘어갈 것, 이것때매 5분 날림
# 풀이 : 람다 표현식 제대로 익힐 것. 답지 풀이와 비슷하나 내 코드가 좀 더 느림. / 소팅한번 덜하고, isdigit으로 할 시 32ms 걸림
# 걸린 시간 : 40분

# Runtime: 54 ms, faster than 18.63% of Python3 online submissions for Reorder Data in Log Files.
# Memory Usage: 14.2 MB, less than 87.38% of Python3 online submissions for Reorder Data in Log Files.