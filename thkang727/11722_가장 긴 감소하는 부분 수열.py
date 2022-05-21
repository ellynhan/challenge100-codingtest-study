#boj 11722
#DP
# 

n=int(input())
dp = [1]*n
ans = 0
if n>=1 and n<=1000:
    nums = list(map(int, input().split()))

    for _ in range(1,n):
        if _ == 1 :
            if nums[_]< nums[_-1]:
                dp[_]=dp[_-1]+1
        else:
            for j in range(_):
                if dp[_]<= dp[j] and nums[_]<nums[j]:
                    dp[_]+=1
    for _ in dp:
        if _ > ans:
            ans = _

    print(ans)
