import sys;

def find(x):
    if parent[x] == x :
        return x
    else:
        parent[x] = find(parent[x])
        return parent[x]

def union(x,y):
    parentX = find(x)
    parentY = find(y)
    if parentX == parentY:
        return
    elif parentX < parentY:
        parent[parentY] = parentX
        parent[y] = parentX
    else :
        parent[parentX] = parentY
        parent[x] = parentY

n, m = map(int, sys.stdin.readline().rstrip().split())

parent = [i for i in range(n)]

ans = 0
for i in range(m):
    n, m = map(int, sys.stdin.readline().rstrip().split())

    parentX = find(n)
    parentY = find(m)
    if parentX == parentY and ans == 0:
        ans = i+1
    else:
        union(parentX, parentY)
print(ans)
