# https://www.acmicpc.net/problem/1260
from collections import deque, defaultdict

def dfs(x):
    print(x, end = ' ')
    for i in tree[x]:
        if not visit_s[i]:
            visit_s[i] = True
            dfs(i)
    return

N, M, V = map(int, input().split(" "))
tree = defaultdict(list)

for _ in range(M):
    start, end = map(int, input().split(" "))
    tree[start].append(end)
    tree[end].append(start)

for t in tree:
    tree[t].sort()
# print(tree)

q = deque([V])
s = deque([V])
visit_q = [False]*(N+1)
visit_s = [False]*(N+1)
visit_q[V], visit_s[V] = True, True

dfs(V)
print()

while q:
    now = q.popleft()
    print(now, end=' ')
    for idx in tree[now]:
        if not visit_q[idx]:
            visit_q[idx] = True
            q.append(idx)




