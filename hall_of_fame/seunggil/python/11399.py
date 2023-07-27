import sys
n = int(input())

inputData = list(map(int, sys.stdin.readline().rstrip().split()))
inputData.sort()

ans = 0
nowTime = 0

for i in inputData :
    ans += i + nowTime
    nowTime += i
print(ans)