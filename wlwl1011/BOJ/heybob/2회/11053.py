import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')

N = int(input())
arr = list(map(int, input().split()))
dp = [1] * (N)
for i in range(N):
    for j in range(i):
        if arr[j] < arr[i]:
            dp[i] = max(dp[i],dp[j]+1)

print(max(dp))