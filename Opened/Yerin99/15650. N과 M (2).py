def get_combination(start, c):
    if len(c) == m:
        print(*c)
        return 0

    for i in range(start, n+1):
        if i not in c:
            get_combination(i+1, c+[i])


n, m = map(int, input().split())
get_combination(1, [])
