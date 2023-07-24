import sys
from collections import defaultdict, deque
input = sys.stdin.readline

n, m, k, x = map(int, input().split())
adj = defaultdict(list)
for _ in range(m):
    a, b = map(int, input().split())
    adj[a].append(b)

answer = []
visited = [0] * (n+1)
dq = deque([(x, 0)])
visited[x] = 1
while dq:
    cur, cost = dq.popleft()
    if cost == k:
        answer.append(cur)
    for nxt in adj[cur]:
        if not visited[nxt]:
            dq.append((nxt, cost+1))
            visited[nxt] = 1
print('\n'.join(map(str, sorted(answer))) if answer else -1)
