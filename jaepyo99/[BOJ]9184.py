def recur(a,b,c):
    if(a<=0 or b<=0 or c<=0):
        return 1
    elif(a > 20 or b > 20 or c > 20):
        return recur(20,20,20)
    if dp[a][b][c]:
        return dp[a][b][c]
    if(a < b < c):
        dp[a][b][c]=recur(a,b,c-1)+recur(a,b-1,c-1)-recur(a,b-1,c)
    else:
        dp[a][b][c]=recur(a-1,b,c)+recur(a-1,b-1,c)+recur(a-1,b,c-1)-recur(a-1,b-1,c-1)
    return dp[a][b][c]
dp=[[[0 for _ in range(21)]for _ in range(21)]for _ in range(21)]
while(True):
    a,b,c=map(int,input().split())
    if(a==-1 and b==-1 and c==-1):
        break
    print("w(%d, %d, %d) = %d"%(a,b,c,recur(a,b,c)))
