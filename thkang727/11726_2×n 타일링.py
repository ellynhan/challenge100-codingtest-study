#boj 11053
#DP
# 

n=int(input())
dp = [1]
if n>=1 and n<=1000:
    for _ in range(1,n):
        if _ == 1 and n> 1 :
            dp.append(2)
        else:
            tmp = (dp[_-2] + dp[_-1])%10007
            dp.append(tmp)
    
    print(dp[n-1])
