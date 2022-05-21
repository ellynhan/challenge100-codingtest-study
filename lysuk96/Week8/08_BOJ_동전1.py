n, k = map(int, input().split(" "))
dp = [0] * (k+1)
coin = []
for i in range(n):
    coin.append(int(input()))

for i in range(n):
    if coin[i] > k :
        continue
    dp[coin[i]] += 1
    for j in range(coin[i]+1, k+1):
        dp[j] += dp[j-coin[i]]
    # print(dp)

print(dp[k])