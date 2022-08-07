import sys

input = sys.stdin.readline

n = int(input())

lst = list(map(int, input().split()))
lst2 = lst[::-1]

dp = [1] * n ## 각 원소는 그 자체로 수열의 시작이 될 수 있다.
dp2 = [0] * n

for i in range(1, n):
    for j in range(i):
        
        if lst[i] > lst[j]:
            dp[i] = max(dp[i], dp[j] + 1)
    
        if lst2[i] > lst2[j]:
            dp2[i] = max(dp2[i], dp2[j] + 1)
        

dp2.reverse()

res = [0] * n
for i in range(n):
    res[i] = dp[i] + dp2[i]
    
print(max(res))