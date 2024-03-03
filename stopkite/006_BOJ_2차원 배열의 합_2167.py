import sys

answer = 0

n, m = map(int, sys.stdin.readline().split())
arr_2d = [
    list(map(int, sys.stdin.readline().split()))
    for _ in range(n)
]

k = int(sys.stdin.readline())
for _ in range(k):
    i, j, x, y = map(int, sys.stdin.readline().split())
    sum_val = 0
    for a in range(i - 1, x):
        for b in range(j - 1, y):
            sum_val += arr_2d[a][b]

    print(sum_val)