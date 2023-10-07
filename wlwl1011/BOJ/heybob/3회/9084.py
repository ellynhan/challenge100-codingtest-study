import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')

for _ in range(int(input())):
    N = int(input())
    coin = list(map(int, input().split()))
    money = int(input())

    dp = [0] * (10001)
    dp[0] = 1
    for i in coin:
        for m in range(i,money+1):
            if dp[m-i]:
                dp[m] += dp[m-i]
    print(dp[money])            