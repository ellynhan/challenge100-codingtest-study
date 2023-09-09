import sys
from collections import deque

input = sys.stdin.readline

n, start, end, d = map(int, input().split())
fees = [tuple(map(int, input().split())) for _ in range(d)]
costs = list(map(int, input().split()))

result = [-sys.maxsize] * n
result[start] = costs[start]

edges = []
for s, e, w in fees:
    w = costs[e] - w
    edges.append((s, e, w))

for _ in range(n - 1):
    for s, e, w in edges:
        if result[s] != -sys.maxsize and result[e] < result[s] + w:
            result[e] = result[s] + w


def bfs(start, end):
    q = deque([start])
    visited = [False] * n
    visited[start] = True
    while q:
        now = q.popleft()
        if now == end:
            return True
        for s, e, _ in edges:
            if s == now and not visited[e]:
                visited[e] = True
                q.append(e)
    return False


is_cycle = False
for s, e, w in edges:
    if result[s] != -sys.maxsize and result[e] < result[s] + w and bfs(s, end):
        is_cycle = True
        break

if result[end] == -sys.maxsize:
    print("gg")
elif is_cycle:
    print("Gee")
else:
    print(result[end])

