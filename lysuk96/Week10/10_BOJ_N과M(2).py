def tracking(idx, depth):
    if depth== M:
        print(*answer)
        return
    else:
        for i in range(idx, N+1):
            answer.append(i)
            tracking(i+1, depth+1)
            answer.pop(-1)

N, M = map(int, input().split(" "))

answer=  []
tracking(1,0)