#
#   boj 10815
#   이진탐색.
# #

n,k= map(int, input().split())


if n <= 200 and n>=1 and k>=1 and k <= 200:
    #dp 배열 생성
    dp= []
    for i in range(201):
        tmp = []
        for j in range(201):
            tmp.append(0)
        dp.append(tmp)
    #print(dp)

    #dp 연산.
    for i in range(1,201):
        for j in range(1,201):

            if i == 1:
                dp[i][j] = j
            elif j == 1:
                dp[i][j] = 1
            else:
                dp[i][j] = dp[i-1][j]+dp[i][j-1]
    
    #답 출력.
    print(dp[n][k]%1000000000)
