import sys

N = int(sys.stdin.readline())
min_gen_num = 0

for cur_num in range(1, N+1):
    gen_num = cur_num
    digit = cur_num

    while cur_num > 0:
        digit += cur_num % 10
        cur_num //= 10

    if digit == N:
        min_gen_num = gen_num
        break

print(min_gen_num)