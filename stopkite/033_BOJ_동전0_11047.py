n, k = map(int, input().split())
coins = []
for _ in range(n):
    coins.append(int(input()))

coins.sort(reverse=True)

idx = 0
for i, coin in enumerate(coins):
    if coin <= k:
        idx = i

answer = 0
for i in range(0, idx + 1):
    a = k % coins[i]
    b = k // coins[i]
    k = a
    answer += b

print(answer)
