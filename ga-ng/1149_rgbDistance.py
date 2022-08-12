import sys

input = sys.stdin.readline

n = int(input())

dp = []

for _ in range(n):
    dp.append(list(map(int, input().split())))


for k in range(1, n):
    
    ## 바로 전이 빨강일 때 최소
    dp[k][0] = min(dp[k-1][1], dp[k-1][2]) + dp[k][0]
    ## 바로 전이 초록일 때 최소
    dp[k][1] = min(dp[k-1][2], dp[k-1][0]) + dp[k][1]
    ## 바로 전이 파랑 일 때 최소
    dp[k][2] = min(dp[k-1][0], dp[k-1][1]) + dp[k][2]
    
print(min(dp[-1]))