import sys

input = sys.stdin.readline

n = int(input())

dp = [0] * 1000001

for i in range(2, n+1): ## i 는 2 부터 n 까지
    dp[i] = dp[i-1] + 1   ## +1 은 계산횟수에 대한 설명이다.
    
    if i % 2 == 0:
        dp[i] = min(dp[i], dp[i//2] + 1)
    if i % 3 == 0:
        dp[i] = min(dp[i], dp[i//3] + 1)
        

print(dp[n])