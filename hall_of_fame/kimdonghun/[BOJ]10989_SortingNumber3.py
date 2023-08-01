import sys

N = int(sys.stdin.readline())
n_list = [0] * 10001

for i in range(N):
    cur_num = int(sys.stdin.readline())
    n_list[cur_num] += 1

for i in range(10001):
    if n_list[i] > 0:
        for j in range(n_list[i]):
            print(str(i)) 