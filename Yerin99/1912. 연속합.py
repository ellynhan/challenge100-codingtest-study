import sys

n = int(sys.stdin.readline())
nums = list(map(int, sys.stdin.readline().split()))
sums = [0]

for i in range(n):
    sums.append(sums[-1] + nums[i])

maxes = [sums[-1]]

for i in range(n):
    maxes.append(max(maxes[-1], sums[-(2+i)]))

maxes = maxes[::-1]

min_sum = 1000
max_sum = max(maxes[1:])

for i in range(n):
    if sums[i] < min_sum:
        min_sum = sums[i]
        max_sum = max(max_sum, maxes[i+1]-sums[i])

print(max_sum)
