import sys

n, testCase = map(int, sys.stdin.readline().split())

dp = [0] * (n+1)
nSum = 0;
for i, num in enumerate(map(int, sys.stdin.readline().split())):
    nSum += num
    dp[i+1] = nSum

for _ in range(testCase):
    start, end = map(int, sys.stdin.readline().split())
    print(dp[end]-dp[start-1])