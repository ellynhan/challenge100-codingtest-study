def get_combination_with_repetition(start, cwr):
    if len(cwr) == m:
        print(*cwr)
        return 0

    for i in range(start, n+1):
        get_combination_with_repetition(i, cwr+[i])


n, m = map(int, input().split())
get_combination_with_repetition(1, [])
