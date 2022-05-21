# https://www.acmicpc.net/problem/6603
# 재귀 이용
def dfs(idx, depth):
    print(lotto, idx, depth)
    if depth == 6:
        print(*lotto)
        return
    for i in range(idx, k):
        lotto.append(l[i])
        dfs(i+1, depth+1)
        lotto.pop(-1)


while True:
    l = list(map(int, input().split(" ")))
    k = l.pop(0)
    if k == 0:
        break
    lotto = []
    dfs(0,0)
    print()

# combinations 이용한 내 풀이
# from itertools import combinations

# l = list(map(int, input().split(" ")))
# k = l.pop(0)

# while k != 0:
#     comb = combinations(l, 6)
#     for c in comb:
#         for i in c:
#             print(i, end=' ')
#         print()
#     print()
#     l = list(map(int, input().split(" ")))
#     k = l.pop(0)
