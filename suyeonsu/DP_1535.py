import sys
input = sys.stdin.readline

n = int(input())
cost = [0] + list(map(int, input().split()))
joy = [0] + list(map(int, input().split()))

size = sum(cost)
if size < 100: 
    print(sum(joy))
else:
    dp = [[0] * (size + 1) for _ in range(n+1)]

    for i in range(1, n+1):
        for j in range(size + 1):
            if j < cost[i]: dp[i][j] = dp[i-1][j]
            else: dp[i][j] = max(dp[i-1][j-cost[i]] + joy[i], dp[i-1][j])
    print(dp[n][99])
    
# 배낭문제를 풀 때는 어떤배낭을 만들지, 그 배낭에 무엇을 넣을지부터 계획하자.
# 먼저 2차원 dp로 풀고, 1차원으로 개선할 수 있다면 개선하자.
