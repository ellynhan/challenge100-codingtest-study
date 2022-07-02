def solution(n):
    dp = [1, 2, 3, 5]
    for i in range(4, n):
        dp.append((dp[i-1] + dp[i-2]) % 1234567)
    
    return dp[n-1]