def tracking(x):
    if x == M:
        print(*answer)
        return
    else:
        for i in range(1, N+1):
            if not visit[i]:
                visit[i] = True
                answer[x] = i
                tracking(x+1)
                answer[x] = 0
                visit[i] = False

    

N, M = map(int, input().split(" "))
visit = [False]*(N+1)
visit[0] = True
answer = [0]*(M)

tracking(0)

# from itertools import permutations

# l = [i for i in range(1, N+1)]
# for p in permutations(l, M):
#     for a in p:
#         print(a, end=' ')
#     print()
