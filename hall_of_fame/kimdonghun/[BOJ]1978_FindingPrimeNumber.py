import sys
N = int(sys.stdin.readline())
num_list = list(map(int, sys.stdin.readline().split()))
prime_cnt = 0
#print(num_list)

for i in num_list :
    cur_num = i
    cur_div_cnt = 0

    for j in range(1,  cur_num + 1) :
        if cur_num % j == 0 :
            cur_div_cnt += 1

    if cur_div_cnt == 2 :
        prime_cnt += 1

print(prime_cnt)