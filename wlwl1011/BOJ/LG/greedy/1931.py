import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')

N = int(input())
arr = []
for _ in range(N):
    arr.append(list(map(int, input().split())))

arr.sort(key = lambda x: (x[1],x[0]))
ans = 0
stack = []
stack.append(arr[0])
for i in range(1,N):
    if stack[-1][1] <= arr[i][0]:
        stack.append(arr[i])

print(len(stack))    