import sys
input = sys.stdin.readline


def bf(cnt, idx):
    global ans
    if cnt == m:
        total = 0
        for hx, hy in house:
            dist = int(1e9)
            for cx, cy in temp:
                dist = min(dist, abs(cx-hx) + abs(cy-hy))
            total += dist
        ans = min(ans, total)
        return
    
    for i in range(idx, len(store)):
        x, y = store[i]
        if not visited[i]:
            visited[i] = 1
            temp.append((x, y))
            bf(cnt+1, i+1)
            visited[i] = 0
            temp.pop()
            
n, m = map(int, input().split())

graph = []
house = []
store = []

for i in range(n):
    graph.append(list(map(int, input().split())))
    for j in range(n):
        if graph[i][j] == 1:
            house.append((i, j))
        if graph[i][j] == 2:
            store.append((i, j))

visited = [0]*14
ans = int(1e9)
temp = []

bf(0, 0)
print(ans)
