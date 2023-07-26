# https://www.acmicpc.net/problem/2133
# i-4, i-6 i-8 ... 계속 2개씩 생김 => 2차원 dp 사용해야함
def tile(n):
    dp = [[0]*(n+1) for _ in range(2)]
    dp[0][0] = 1
    dp[0][1] = 3
    if n>1:
        for i in range(2, n+1):
            dp[1][i] = dp[0][i-2] + dp[1][i-1]
            dp[0][i] = dp[0][i-1]*3 + dp[1][i] * 2
    # print(dp)
    return (dp[0][n]) 

    # dp = [0]*(n+1) #그냥 dp 사용시 틀림
    # dp[0] = 1
    # dp[1] = 3
    # if n<2:
    #     return dp[n]
    # for i in range(2, n+1):
    #     dp[i] = dp[i-2]*2 + dp[i-1]*3
    # return dp[n]


N = int(input())
if N%2 != 0 :
    print(0)
else:
    print(tile(N//2))