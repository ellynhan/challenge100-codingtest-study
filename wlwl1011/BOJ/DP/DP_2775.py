import sys, io, os, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s: stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

dp = [[0]*15 for _ in range(14+1)]

for i in range(1,15):
    dp[0][i] = i  #각층에는 1호부터 있으며, 0층의 i호에는 i명이 산다.
    dp[i][1] = 1 #각 층의 1호는 1이다.


for i in range(1, 14+1): #1층부터 14층까지 높이
    for j in range(2,14+1):
        dp[i][j] = dp[i][j-1] + dp[i-1][j]

T = int(input())

for _ in range(T):
    k = int(input())
    n = int(input())
    print(dp[k][n])