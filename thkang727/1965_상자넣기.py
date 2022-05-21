#
#   1965
#   DP
# #

n = int(input())


dp=[]
arr_t=list((map(int, input().split())))
ans=1
#print(arr_t)
for _ in range(len(arr_t)):
    dp.append(1)
for _ in range(1,len(arr_t)):
    for j in range(_):
        if arr_t[_]>arr_t[j]:
            dp[_]=max(dp[_],dp[j]+1)

for _ in range(len(arr_t)):
    if dp[_]>ans:
        ans = dp[_]

print(ans)
