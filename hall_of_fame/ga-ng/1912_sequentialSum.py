import sys

input = sys.stdin.readline

n = int(input())

arr = list(map(int, input().split()))

dp = [0] * (n)

dp[0] = arr[0]
# dp[1] = max(arr[1], arr[1] + dp[0])

for k in range(1, n):
    dp[k] = max(arr[k], arr[k] + dp[k-1])
    
    # print(dp[0:n+1])
    
print(max(dp))