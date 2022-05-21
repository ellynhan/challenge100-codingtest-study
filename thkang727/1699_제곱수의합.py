#
#   1010
#   dp 실버3
# #

n = int(input())
dp = [0 for j in range(n+1)]
square = []
for i in range(1,318):
    square.append(i*i)

for i in range(1,n+1):
    tmp = []
    for j in square:
        if j>i:
            break
        tmp.append(dp[i-j])
    dp[i] = min(tmp) + 1
print(dp[n])
