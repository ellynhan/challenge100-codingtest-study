from collections import deque

def solution(n, edge):
    adj = {i: [] for i in range(1, n+1)}
    for a, b in edge:
        adj[a].append(b)
        adj[b].append(a)
        
    dist = [0] * (n+1)
    dq = deque()
    dq.append((1, 0))
    dist[1] = 0
    while dq:
        i, d = dq.popleft()
        for nxt in adj[i]:
            if nxt != 1 and not dist[nxt]:
                dist[nxt] = d+1
                dq.append((nxt, d+1))
                
    return dist.count(max(dist[2:]))
