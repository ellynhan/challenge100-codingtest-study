import sys

N = int(sys.stdin.readline())
N_list = list(map(int, sys.stdin.readline().split()))

right_upper = [-1] * N
s = []

s.append(0)

for i in range(1, N):
    while s and N_list[s[-1]] < N_list[i]:
        right_upper[s.pop()] = N_list[i]
    s.append(i)

print(*right_upper)
