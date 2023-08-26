import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))


dp = [ [0,0] for _ in range(41) ]

dp[0] = [1,0]
dp[1] = [0,1]


for i in range(2,41):
    dp[i][0] = dp[i-2][0] + dp[i-1][0]
    dp[i][1] = dp[i-1][0] + dp[i-1][1]

T = int(input())

for _ in range(T):
    n = int(input())
    print(dp[n][0], dp[n][1])