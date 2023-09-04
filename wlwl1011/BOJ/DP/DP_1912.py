import sys, io, os, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda: os.write(1, stdout.getvalue()))

N = int(input())
arr = [0] + list(map(int, input().split()))
dp = [-1000] * (N+1)

for i in range(1,N+1):
    dp[i] = max(dp[i-1]+arr[i],arr[i])

print(max(dp))