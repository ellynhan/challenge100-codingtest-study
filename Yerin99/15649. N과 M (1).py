def get_permutation(p):
    if len(p) == m:
        print(*p)
        return 0

    for i in range(1, n+1):
        if i not in p:
            get_permutation(p+[i])


n, m = map(int, input().split())
get_permutation([])
