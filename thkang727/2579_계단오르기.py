#boj 2579
# DP
#



stair = [0]
dp = []
sum = 0

n = int(input())

if n>300:
    quit()

for i in range(n):
    tmp = int(input())
    if tmp >0 & tmp <=10000:
        stair.append(tmp)
if n>0:
    dp.append(0)
    dp.append(stair[1])
if n>1:
    dp.append(stair[2]+stair[1])
if n>2:
    dp.append(max(stair[1]+stair[3], stair[2]+stair[3]))


if n>3:
    for i in range(4,n+1):
        dp.append(max(dp[i-2]+stair[i],dp[i-3]+stair[i-1]+stair[i]))

print(dp[n])
