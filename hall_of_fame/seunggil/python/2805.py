# https://www.acmicpc.net/problem/2805

# https://www.notion.so/2805-07d96b48757c41a8a000e4e8fe89b21f
import math
import sys
n, total = map(int, input().split())
inputData = list(map(int, sys.stdin.readline().rstrip().split()))

#내림차순으로 정렬하고, 0을 추가한다.
inputData.sort(key= lambda x: (-x))
inputData.append(0)

dp = [0 for _ in range(n+1)]

for i in range(1,n):
    dp[i] = dp[i-1] + (inputData[i-1]-inputData[i]) * i
dp[n] = dp[n-1] + inputData[n-1] * n

ans = -1

while dp[ans] > total:
    ans -= 1
ans = n + ans + 1

print(inputData[ans] - math.ceil((total - dp[ans])/(ans+1)))