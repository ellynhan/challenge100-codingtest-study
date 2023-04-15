from collections import deque
import sys
input = sys.stdin.readline

n, m, k = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(n)]
woods = {(i, j): deque() for i in range(n) for j in range(n)}
ground = [[5] * n for _ in range(n)]
for _ in range(m):
    x, y, z = map(int, input().split())
    woods[(x-1, y-1)].append(z)


def ss():
    for (i, j), ages in woods.items():
        dq = deque()
        dead = 0
        for age in ages:
            if ground[i][j] >= age:
                ground[i][j] -= age
                dq.append(age+1)
            else:
                dead += age // 2
        woods[(i, j)] = dq
        ground[i][j] += dead


def fw():
    dx = [-1, -1, -1, 0, 0, 1, 1, 1]
    dy = [-1, 0, 1, -1, 1, -1, 0, 1]
    for (i, j), ages in woods.items():
        for age in ages:
            if age % 5 == 0:
                for d in zip(dx, dy):
                    ni, nj = i+d[0], j+d[1]
                    if 0 <= ni < n and 0 <= nj < n:
                        woods[(ni, nj)].appendleft(1)
        ground[i][j] += a[i][j]


while k:
    ss()
    fw()
    k -= 1

answer = 0
for ages in woods.values():
    answer += len(ages)
print(answer)
