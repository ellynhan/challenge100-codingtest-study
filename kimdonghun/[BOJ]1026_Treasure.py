import sys

N = int(sys.stdin.readline())
A_list = list(map(int, sys.stdin.readline().split()))
B_list = list(map(int, sys.stdin.readline().split()))

A_list.sort()
B_max_list = sorted(B_list, reverse=True)

ans = 0
i = 0

for A in A_list:
    ans += A * B_max_list[i]
    i += 1

#print(A_list)
#print(B_max_list)

print(ans)