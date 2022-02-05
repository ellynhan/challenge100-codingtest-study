import sys

N = int(sys.stdin.readline())
money_list = [500, 100, 50, 10, 5, 1]

ans_num = 0
N = 1000 - N

for money in money_list:
    #print(N, ans_num)

    ans_num += N // money
    N %= money

print(ans_num)
