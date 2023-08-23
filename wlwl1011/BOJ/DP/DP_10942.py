import sys, io, os, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda: os.write(1, stdout.getvalue()))


N = int(input())
arr = list(map(int, input().split()))
dp = [[0]*N for _ in range(N)]

for i in range(N): #자기 자신은 팰린드롬
    dp[i][i] = 1

for i in range(N-1):
    if arr[i] == arr[i+1]: dp[i][i+1] = 1
    else: dp[i][i+1] = 0

for cnt in range(N-2):
    for i in range(N-2-cnt):
        j = i + 2 + cnt
        if arr[i] == arr[j] and dp[i+1][j-1] == 1:
            dp[i][j] = 1
            

M = int(input())
for i in range(M):
    a, b = map(int, input().split())
    print(dp[a-1][b-1])
     
                

              
    