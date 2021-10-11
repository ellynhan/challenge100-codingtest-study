T = int(input())

for _ in range(T):
    N = int(input())
    if N == 0:
        print(1, 0)
    else:
        dp = [0] * 41
        dp[0] = 0
        dp[1] = 1
        for i in range(2, 41):
            dp[i] = dp[i-1] + dp[i-2]
        print(dp[N-1], dp[N])