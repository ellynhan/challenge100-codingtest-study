from collections import deque, defaultdict

def is_promising(x):
    q= deque([start])
    visit = [False] * (N+1)
    while q:
        tmp = q.popleft()
        if tmp == end:
            return True
        for island, limit in v[tmp]:
            if not visit[island] and limit>=x:
                visit[island] = True
                q.append(island)
    return False

N, M = map(int, input().split(" "))
v = defaultdict(list)
for _ in range(M):
    a, b, c = map(int, input().split(" "))
    v[a].append((b,c))
    v[b].append((a,c))

start, end = map(int, input().split(" "))
answer = 0

lo, hi = 0, 1000000001
while lo < hi:
    mid = (lo + hi) // 2
    if is_promising(mid):
        lo = mid+1
    else:
        hi = mid

print(lo-1)