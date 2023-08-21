# import sys, io, os, atexit
# input = lambda : sys.stdin.readline().rstrip('\r\n')
#stdout = io.BytesIO()
# sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
# atexit.register(lambda: os.write(1, stdout.getvalue()))

n = int(input())
arr = []
for _ in range(n):
    arr.append(list(map(int,input().split())))

dp = [[0] * n for _ in range(n)]
dp[0][0] = 1


for i in range(n):
    for j in range(n):
        # print('dp')
        # for index_i in range(n):
        #     for index_j in range(n):
        #         print(dp[index_i][index_j], end=' ')
        #     print()    
        if i == n - 1 and j == n - 1:
            print(dp[i][j])
            break

        cur = arr[i][j]

        if j + cur < n:
            dp[i][j + cur] += dp[i][j]

        if i + cur < n:
            dp[i + cur][j] += dp[i][j]