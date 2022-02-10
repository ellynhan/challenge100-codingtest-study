def get_permutation_with_repetition(pwr):
    if len(pwr) == m:
        print(*pwr)
        return 0

    for i in range(1, n+1):
        get_permutation_with_repetition(pwr+[i])


n, m = map(int, input().split())
get_permutation_with_repetition([])
