import sys

input = lambda : sys.stdin.readline().rstrip('\r\n')

N = int(input())

arr = list(map(int, input().split()))
stack = []
answer = [-1]*N

stack.append(0)
for i in range(1,N):
    while stack and arr[stack[-1]] < arr[i]:
        answer[stack.pop()] = arr[i]
    stack.append(i)

print(*answer)