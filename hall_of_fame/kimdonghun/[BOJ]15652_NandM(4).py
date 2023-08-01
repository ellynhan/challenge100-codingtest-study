import sys

N, M = map(int, sys.stdin.readline().split())
answer = []
#is_used = [False] * 10

def solution(start):
    if len(answer) == M:
        print(' '.join(map(str,answer)))
        return

    for i in range(start - 1, N+1):
        answer.append(i)
        solution(i+1)
        answer.pop()

solution(2)
