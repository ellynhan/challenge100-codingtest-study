import sys

def find(x):
    if parent[x] == x:
        return x
    else:
        parent[x] = find(parent[x])
        return parent[x]

def union(x,y):
    parentX = find(x)
    parentY = find(y)

    if parentX == parentY:
        return
    elif parentX < parentY :
        parent[parentY] = parentX
    else:
        parent[parentX] = parentY

N, M = map(int, sys.stdin.readline().rstrip().split())

parent = [i for i in range(N+1)]
inputData = []

ans = 0
maxValue = 0

for _ in range(M):
    start, end, value = map(int, sys.stdin.readline().rstrip().split())
    inputData.append([value,start,end])
inputData.sort(key=lambda x: x[0])

for value, start, end in inputData:
    if find(start) != find(end) :
        ans += value
        union(start,end)
        maxValue = max(maxValue,value)

print(ans - maxValue)