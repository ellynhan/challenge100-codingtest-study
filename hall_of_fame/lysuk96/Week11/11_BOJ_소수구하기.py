M, N = map(int, input().split(" "))
dp = [True]*(N+1)
dp[1] = False
for i in range(2, N+1):
    if not dp[i]:
        continue
    else:
        for j in range(2, N//i+1):
            dp[i*j] = False

for i in range(M, N+1):
    if dp[i]:
        print(i)
