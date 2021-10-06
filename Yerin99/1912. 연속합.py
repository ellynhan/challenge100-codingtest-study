import sys

n = int(sys.stdin.readline())
nums = list(map(int, sys.stdin.readline().split()))
sums = [nums[0]]

for i in range(1, n):
    sums.append(nums[i] + max(sums[-1], 0))

print(max(sums))
