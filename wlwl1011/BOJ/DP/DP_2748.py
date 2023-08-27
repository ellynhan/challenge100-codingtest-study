import sys, io, os, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s: stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

dp = [0] * 91

dp[1] = 1

for i in range(2,91):
    dp[i] = dp[i-1] + dp[i-2]

n = int(input())
print(dp[n])
