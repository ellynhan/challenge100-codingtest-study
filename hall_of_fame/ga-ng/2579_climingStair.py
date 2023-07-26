import sys

input = sys.stdin.readline

n = int(input())

dp = [0] * n
stairs = []

for _ in range(n):
    stairs.append(int(input().rstrip()))

dp[0] = stairs[0]
if n > 1:
    dp[1] = max(stairs[0] + stairs[1], stairs[1] )
if n > 2:
    dp[2] = max(stairs[1] + stairs[2], stairs[0] + stairs[2])


for k in range(3, n):
    dp[k] = max(stairs[k] + stairs[k-1] + dp[k-3], stairs[k] + dp[k-2])

print(dp[-1])