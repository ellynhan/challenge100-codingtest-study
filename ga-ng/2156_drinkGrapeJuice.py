import sys

input = sys.stdin.readline

n = int(input())

arr = [int(input().rstrip()) for _ in range(n)]

dp = [0] * n

dp[0] = arr[0]

if n > 1:
    dp[1] = arr[0] + arr[1]


for i in range(2, n):
    dp[i] = max(arr[i] + arr[i-1] + dp[i-3], arr[i] + dp[i-2], dp[i-1])
    


print(max(dp))