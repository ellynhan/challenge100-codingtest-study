import sys

N, M = map(int, sys.stdin.readline().split())
answer = []
is_used = [False] * 10

def solution(start):
    if(len(answer) == M):
        print(' '.join(map(str,answer)))
        return

    for i in range(start, N+1):
        if not is_used[i]:
            is_used[i] = True

            answer.append(i)
            solution(i+1)
            answer.pop()

            is_used[i] = False

solution(1)
