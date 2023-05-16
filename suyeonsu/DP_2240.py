t, w = map(int, input().split())
tree = [0] + [int(input()) for _ in range(t)]
dp = [[0] * (w+1) for _ in range(t+1)]

for sec in range(1, t+1):
    for i in range(w+1):
        if i == 0:
            if tree[sec] == 1: dp[sec][i] = dp[sec-1][0]+1
            else: dp[sec][i] = dp[sec-1][0]
        else:
            if (tree[sec] == 1 and i%2 == 0) or (tree[sec] == 2 and i%2 == 1):
                dp[sec][i] = max(dp[sec-1][i], dp[sec-1][i-1])+1
            else:
                dp[sec][i] = max(dp[sec-1][i], dp[sec-1][i-1])
print(max(dp[t]))
