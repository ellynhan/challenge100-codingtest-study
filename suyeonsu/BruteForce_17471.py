from itertools import combinations
from collections import deque

def check(s):
    visited = set([list(s)[0]])
    dq = deque([list(s)[0]])
    while dq:
        x = dq.popleft()
        for nxt in adj[x]:
            if nxt not in visited and nxt in s:
                visited.add(nxt)
                dq.append(nxt)
    return 1 if visited == s else 0


n = int(input())
area = list(map(int, input().split()))
adj = {i: set(map(int, input()[2:].split())) for i in range(1, n+1)}
answer = 2147000000

for k in range(1, n):
    for case in list(combinations(range(1, n+1), k)):
        A = set(case)
        B = set(range(1, n+1)) - A
        if check(A) and check(B):
            totA, totB = 0, 0
            for a in A: totA += area[a-1]
            for b in B: totB += area[b-1]
            answer = min(answer, abs(totA-totB))
print(answer if answer != 2147000000 else -1)
