#boj 11053
#DP
# 

n=int(input())
high = 0
if n>=1 and n<=1000:
    dp= []
    num = list(map(int, input().split()))
    
    dp.append(1)
    if n>=2 and (num[1]>num[0]):
        dp.append(2)
    else:
        dp.append(1)        
    for _ in range(2,n):
        tmp = 1
        up = 0
        for j in range(_-1, -1, -1):
            if num[_] > num[j]:
                if dp[j]>= tmp:
                    tmp = dp[j]
                    up =1
        if up == 1:
            dp.append(tmp+1)
        else:
            dp.append(tmp)
    
    for i in dp:
        if high<i:
            high=i
    print(high)
