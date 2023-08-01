import sys

N, K = map(int, sys.stdin.readline().split())
coin_l = []

for i in range(N):
    coin_n = int(sys.stdin.readline())
    coin_l.append(coin_n)

ans_num = 0
coin_l.sort(reverse=True)

for coin in coin_l:
    ans_num += K // coin
    K %= coin

    if K < 0:
        break

#print(coin_l)
print(ans_num)