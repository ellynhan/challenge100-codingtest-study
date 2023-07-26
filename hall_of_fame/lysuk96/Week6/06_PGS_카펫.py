#https://programmers.co.kr/learn/courses/30/lessons/42842
def solution(brown, yellow):
    for m in range(1,2500):
        for n in range(1, m+1):
            if m*n == yellow and (2*m+2*n+4) == brown:
                return [m+2, n+2]