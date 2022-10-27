c, n = map(int, input().split())
dp = [1e9] * (c+100)
for _ in range(n):
    cost, cnt = map(int, input().split())
    dp[cnt] = min(dp[cnt], cost)
    for i in range(cnt+1, c+100):
        dp[i] = min(dp[i-cnt] + cost, dp[i])
print(min(dp[c:c+100]))

"""
문제에서 '적어도 c명'이라는 조건을 계속 간과하고 있었다
즉, 'c명을 모으는 비용' >= 'c명 이상을 모으는 비용'이라면 c명 이상을 모으는 것이 유리한 것이다
"""
