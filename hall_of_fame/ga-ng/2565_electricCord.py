import sys

input = sys.stdin.readline

n = int(input())

cord = []
dp = [1] * n

for _ in range(n):
    cord.append(list(map(int, input().split())))
    
cord.sort(key = lambda x : x[0])

for i in range(1, n):
    for j in range(i):
        
        if cord[i][1] > cord[j][1]:
            dp[i] = max(dp[i], dp[j] + 1)
            

print(n - max(dp))