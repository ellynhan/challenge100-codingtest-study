import sys

N, M = map(int, sys.stdin.readline().split())
answer = []
#is_used = [False] * 10

def solution():
    if len(answer) == M:
        print(' '.join(map(str, answer)))
        return

    for i in range(1, N+1):
        '''
        if not is_used[i]:
            is_used[i] = True

            is_used[i] = False
        '''
        answer.append(i)
        solution()
        answer.pop()

solution()
