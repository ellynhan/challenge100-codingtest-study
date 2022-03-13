import sys

N, M = map(int, sys.stdin.readline().split())

is_used = [False] * 10
answer = []

def solution():
    global answer
    if(len(answer) == M) :
        print(' '.join(map(str,answer)))
        return

    for i in range(1, N+1):
        if not is_used[i]:
            is_used[i] = True

            answer.append(i)
            solution()
            answer.pop()

            is_used[i] = False

solution()
#print(answer)
#print(is_used)
