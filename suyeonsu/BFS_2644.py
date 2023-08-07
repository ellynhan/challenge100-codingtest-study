from collections import defaultdict, deque

n = int(input())
s, e = map(int, input().split())
adj = defaultdict(list)
for _ in range(int(input())):
    x, y = map(int, input().split())
    adj[x].append(y)
    adj[y].append(x)
visited = [0] * (n+1)
answer = 0

dq = deque([(s, 0)])
visited[s] = 1
while dq:
    cur, cost = dq.popleft()
    if cur == e:
        answer = cost
        break
    for nxt in adj[cur]:
        if not visited[nxt]:
            dq.append((nxt, cost+1))
            visited[nxt] = 1
print(answer if answer else -1)
