from collections import deque, defaultdict
from re import L
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

dfs = [V]
while s:
    now = s[-1]
    if not visit_s[now]:
        dfs.append(now)
    visit_s[now] = True
    flag = True
    for idx in tree[now]:
        if not visit_s[idx]:
            flag = False
            s.append(idx)
            break
    if flag:
        s.pop()
# dfs.append(V)
# dfs.reverse()
print(*dfs)

# while s:
#     now = s.pop()
#     if visit_s[now]:
#         print(now, end=' ')
#     visit_s[now] = True

#     for idx in tree[now]:
#         # print(idx)
#         if not visit_s[idx]:
#             s.appendleft(idx)

while q:
    now = q.popleft()
    print(now, end=' ')
    for idx in tree[now]:
        if not visit_q[idx]:
            visit_q[idx] = True
            q.append(idx)




