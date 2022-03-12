#
#   9655
#   dp
# #
# 


n = int(input())
dp = []
sorc = 0
for i in range(n):
    if i%2 == 0 :
        dp.append('SK')
    else:
        dp.append('CY')

print(dp[n-1])
