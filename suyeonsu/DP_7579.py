n, m = map(int, input().split())
memory = [0] + list(map(int, input().split()))
cost = [0] + list(map(int, input().split()))

dp = [[0] * (sum(cost)+1) for _ in range(n+1)]
answer = 1e9
for i in range(1, n+1):
    for j in range(sum(cost)+1):
        if j < cost[i]: dp[i][j] = dp[i-1][j]
        else: 
            dp[i][j] = max(dp[i-1][j-cost[i]] + memory[i], dp[i-1][j])
            if dp[i][j] >= m:
                answer = min(j, answer)
print(answer)

# 0-1 배낭문제의 경우 일정한 패턴이 있기 때문에 패턴만 잊지 않으면 쉽게 풀 수 있음
