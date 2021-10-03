import sys

n, m = map(int, sys.stdin.readline().split())
nums = list(map(int, sys.stdin.readline().split()))
sums = [0]

for i in range(n):
    sums.append(sums[-1] + nums[i])

for _ in range(m):
    a, b = map(int, sys.stdin.readline().split())
    print(sums[b]-sums[a-1])
