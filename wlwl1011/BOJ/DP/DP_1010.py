import sys, io, os, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda: os.write(1, stdout.getvalue()))

T = int(input())

dp = [[0 for _ in range(30)] for _ in range(30)]

for i in range(1,30):
    dp[1][i] = i

for i in range(2,30):
    for j in range(i,30):
        if i == j:
            dp[i][j] = 1
        else:
            dp[i][j] += sum(dp[i-1][:j]) 

# for i in range(30):
#     print(dp[i])                  

for _ in range(T):
    N, M = map(int, input().split())
    print(dp[N][M])            