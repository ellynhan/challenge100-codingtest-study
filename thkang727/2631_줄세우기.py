#
#   boj 2631
#   dp.
# #

n = int(input())

num = []
dp = []

for i in range(n):
    tmp = int(input())
    if tmp >=1 and tmp <=200:
        num.append(tmp)
        dp.append(1)

for i in range(1,n):
    for j in range(i):
        if num[i] > num[j]:
            if dp[i]<= dp[j]:
                dp[i] = dp[j]+1
highnum=0
for i in range(n):
    if highnum < dp[i]:
        highnum=dp[i]
print(n-highnum)
