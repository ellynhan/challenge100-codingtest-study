import sys

n, m = map(int, sys.stdin.readline().split())
arr = list(map(int, sys.stdin.readline().split()))

for i in range(n - 1):
    arr[i + 1] += arr[i]
arr = [0] + arr

for _ in range(m):
    i, j = map(int, sys.stdin.readline().split())
    print(arr[j] - arr[i - 1])
