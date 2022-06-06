from collections import deque
# n = int(input())
# graph = []
# for _ in range(n):
#     graph.append(list(map(int, input().split())))
#
# answer = 0
# start = (0, 1)
# deque = ([start])
# while deque:
#     pipe = deque.pop()
#     dx = [0, 1, 1]
#     dy = [1, 0, 1]
#     for i in range(3):
#         x = pipe[0] + dx[i]
#         y = pipe[1] + dy[i]
#
#         if x >= n or y >= n or graph[x][y] == 1:
#             continue
#
#         graph[x][y] = 1
#         print(x,y)
#         deque.append((x, y))
#         if x == n-1 and y == n-1:
#             answer += 1
#
# print(answer)

# bfs로 시도했으나 실패..
# dfs로 변경

import sys
input = sys.stdin.readline
def dfs(x, y, direction):
    global count
    if x == n - 1 and y == n - 1: count += 1
    if direction == 0:
        if y + 1 < n and s[x][y + 1] == 0: dfs(x, y + 1, 0)
        if x + 1 < n and y + 1 < n:
            if s[x][y + 1] == 0 and s[x + 1][y + 1] == 0 and s[x + 1][y] == 0:
                dfs(x + 1, y + 1, 2)
    elif direction == 1:
        if x + 1 < n and s[x + 1][y] == 0: dfs(x + 1, y, 1)
        if x + 1 < n and y + 1 < n:
            if s[x][y + 1] == 0 and s[x + 1][y + 1] == 0 and s[x + 1][y] == 0:
                dfs(x + 1, y + 1, 2)
    elif direction == 2:
        if y + 1 < n and s[x][y + 1] == 0: dfs(x, y + 1, 0)
        if x + 1 < n and s[x + 1][y] == 0: dfs(x + 1, y, 1)
        if x + 1 < n and y + 1 < n:
            if s[x][y + 1] == 0 and s[x + 1][y + 1] == 0 and s[x + 1][y] == 0:
                dfs(x + 1, y + 1, 2)
n = int(input())
s = [list(map(int, input().split())) for i in range(n)]
count = 0
dfs(0, 1, 0)
print(count)