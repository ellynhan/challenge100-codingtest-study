import sys

N = int(sys.stdin.readline())
lope_list = []

for i in range(N):
    lope_list.append(int(sys.stdin.readline()))

lope_list.sort()
max_mass = 0
cnt = 0

for lope in lope_list:
    cur_mass = lope * (N-cnt)

    if cur_mass > max_mass:
        max_mass = cur_mass

    cnt += 1

print(max_mass)
    