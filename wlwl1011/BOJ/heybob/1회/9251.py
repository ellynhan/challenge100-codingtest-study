import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')

s1 = input()
s2 = input()

l1, l2 = len(s1), len(s2)
dp = [0] * l2

for i in range(l1):
    cnt = 0
    for j in range(l2):
        if cnt < dp[j]:
            cnt = dp[j]
        elif s1[i] == s2[j]:
            dp[j] = cnt + 1

print(max(dp))                