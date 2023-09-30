import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')

for _ in range(int(input())):
    N = int(input())
    arr = list(map(int, input().split()))
    arr.sort()
    ans = 0
    for i in range(N-2):
        ans = max(arr[i+2]-arr[i], ans)
    print(ans)    