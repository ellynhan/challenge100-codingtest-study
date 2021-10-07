import collections

n, m = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(n)]

def bfs():
    queue = collections.deque()
    queue.append((0,0))
    check = [[False] * m for _ in range(n)]
    dx, dy = [-1, 1, 0, 0], [0, 0, -1, 1]
    count = 0

    while queue:
        x, y = queue.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < n and 0 <= ny < m:
                if graph[nx][ny] == 0 and check[nx][ny] == False:
                    check[nx][ny] = True
                    queue.append((nx, ny))

                elif graph[nx][ny] == 1:
                    graph[nx][ny] = 0
                    count += 1
                    check[nx][ny] = True
    return count

result = []
time = 0
while True:
    count = bfs()
    result.append(count)
    if count == 0:
        break
    time += 1

print(time)
print(result[-2])