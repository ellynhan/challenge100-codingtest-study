import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')

T = int(input())

for _ in range(T):
    N = int(input())
    arr = []
    for _ in range(N):
        arr.append(list(map(int, input().split())))
    arr.sort()    
    stack = []
    stack.append(arr[0])
    cnt = 1
    for i in range(1,N):
        if arr[i][0] < stack[-1][0] or arr[i][1] < stack[-1][1]:
            stack.append(arr[i])
            cnt += 1
    print(cnt)