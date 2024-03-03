n, s, p = map(int, input().split())

if n == 0:
    print(1)
else:
    scores = list(map(int, input().split()))
    if n == p and scores[-1] >= s:
        print(-1)
    else:
        rank = n + 1
        for i in range(n):
            if scores[i] <= s:
                rank = i + 1
                break
        print(rank)

