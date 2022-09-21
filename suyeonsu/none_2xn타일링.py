# 처음에 이렇게 dp 배열에 저장해서 풀었는데
def solution(n):
    dp = [0] * (n+1)
    dp[1] = 1
    dp[2] = 2
    for i in range(3, n+1):
        dp[i] = (dp[i-1] + dp[i-2]) % 1000000007
    return dp[n]

# 변수를 2개만 사용해서 더 효율성을 높일 수 있었다! 매우매우 깔끔
def solution(n):
    a, b = 1, 1
    for i in range(n-1):
        a, b = b, (a+b) % 1000000007
    return b
