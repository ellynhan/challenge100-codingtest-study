#0124
import sys
sys.setrecursionlimit(10**5)

def find_parent(parent, a):
    if parent[a] == a:
        return a
    else:
        parent[a] = find_parent(parent, parent[a])
        return find_parent(parent, parent[a])

def union_parent(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b


n, m = map(int, sys.stdin.readline().split())
parent = [i for i in range(n+1)]

for _ in range(m):
    op, a, b = map(int, sys.stdin.readline().split())
    if op == 0:
        union_parent(parent, a, b)
    else:
        if find_parent(parent, a) == find_parent(parent, b):
            print("YES")
        else:
            print("NO")

