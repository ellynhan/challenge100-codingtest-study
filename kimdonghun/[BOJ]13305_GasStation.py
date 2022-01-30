import sys

N = int(sys.stdin.readline())
path_len = list(map(int, sys.stdin.readline().split()))
gas_price = list(map(int, sys.stdin.readline().split()))

tot_fee = 0
cur_price = gas_price[0]
i = 0

for price in gas_price:
    if price < cur_price:
        cur_price = price

    if i == len(path_len):
        break

    tot_fee += (cur_price * path_len[i])
    i += 1

print(tot_fee)