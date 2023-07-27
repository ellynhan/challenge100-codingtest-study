# https://www.acmicpc.net/problem/9663
# 1트 : permutations로 풀라 했으나 시간초과로 실패...

# 재귀 이용한 풀이
n = int(input())

ans = 0
row = [0] * n

def is_promising(x):
    for i in range(x):
        if row[x] == row[i] or abs(row[x] - row[i]) == abs(x - i):
            return False
    return True

def n_queens(x):
    global ans
    if x == n:
        ans += 1
    else:
        for i in range(n):
            # [x, i]에 퀸을 놓겠다.
            row[x] = i
            if is_promising(x):
                n_queens(x+1)

n_queens(0)
print(ans)

# 시간 초과
# from itertools import permutations, combinations

# N = int(input())
# table = [i for i in range(N)]
# # print(table)
# answer = 0
# candidate = []

# for p in permutations(table, N):
#     tmp = []
#     for i in range(N):
#         tmp.append((i, p[i]))
    
#     flag = True
#     for a, b in combinations(tmp, 2):
#         if abs(b[0] - a[0]) == abs(b[1] - a[1]):
#             flag = False
#             break
#     if flag:
#         answer+=1
# print(answer)