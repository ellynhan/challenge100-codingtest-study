import sys

input = sys.stdin.readline

str1 = input().rstrip()
str2 = input().rstrip()

dp = [0] * max(len(str1), len(str2))

for i in range(len(str1)):
    cnt = 0
    for j in range(len(str2)):
        
        if cnt < dp[j]:
            cnt = dp[j]
        elif str1[i] == str2[j]:
            dp[j] = cnt + 1
            
print(max(dp))