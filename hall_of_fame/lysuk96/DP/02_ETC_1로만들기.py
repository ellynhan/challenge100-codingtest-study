# 1로만들기 (동빈나)

X = int(input())
DP = [300001] * (X+1)

for i in range(2, X+1):
    if i %5==0:
        DP[i] = min(DP[i], DP[i//5] +1)
    if i %3 == 0:
        DP[i] = min(DP[i], DP[i//3]+1)
    if i %2 == 0:
        DP[i] = min(DP[i], DP[i//2]+1)
    DP[i] = min(DP[i], DP[i-1]+1)
print(DP[X])