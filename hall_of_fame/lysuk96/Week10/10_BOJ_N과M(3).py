def tracking(x):
    if x == M:
        print(*answer)
    else:
        for i in range(1, N+1):
            # if not visit[i]:
                # visit[i] = True
            answer[x] = i
            tracking(x+1)
                # visit[i] = False

N, M = map(int, input().split(" "))
answer = [0]*(M)
# visit = [False]*(N+1)

tracking(0)

