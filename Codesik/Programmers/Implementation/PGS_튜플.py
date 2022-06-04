"""
1. 주어진 문자열 파싱
2. {}안 갯수 파악해서, s의 길이를 파악.
3. 1 ~ s 까지의 길이별로, 하나씩 변수를 구한다.
4. 변수 차례대로 return
"""
def solution(s):
    answer = []

    s = s.replace('{', '[')
    s = s.replace('}', ']')
    s = sorted(eval(s), key=lambda x: len(x))

    for el in s:
        for num in el:
            if num not in answer:
                answer.append(num)
    return answer