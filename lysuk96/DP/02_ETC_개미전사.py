# 개미전사 (동빈나)

N = int(input())
K = list(map(int, input().split()))

DP = [0] * N
DP[0] = K[0]
DP[1] = max(K[0],K[1])

for i in range(2, N):
    DP[i] = max(DP[i-1], DP[i-2]+K[i])

print(DP[N-1])