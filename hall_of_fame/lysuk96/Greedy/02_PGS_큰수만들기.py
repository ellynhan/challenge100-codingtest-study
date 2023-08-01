#큰 수 만들기(실패)
#앞자리수가 크도록 스택사용
from collections import deque

def solution(number, k):
    s = deque()
    
    for digit in number:
        while s and s[-1] < digit and k>0:
            s.pop()
            k-=1
        s.append(digit)
        # print(s)

    # stack을 list로 사용할 때 사용가능
    # if k > 0 :
    #     s = s[:-k]

    for _ in range(k):
        s.pop()

    answer = ''.join(s)
    return answer

print(solution("1000", 1))
