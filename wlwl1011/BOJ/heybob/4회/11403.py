import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')
from collections import deque


def findRoad(node):
    queue = deque()
    queue.append(node)

    while queue:
        n = queue.popleft()

        for i in range(N):
            if visited[node][i] == 0 and graph[n][i] == 1:
                visited[node][i] = 1
                queue.append(i)

graph = []
N = int(input())
visited = [[0 for _ in range(N)] for _ in range(N)]
for _ in range(N):
    graph.append(list(map(int, input().split())))

for i in range(N):
    findRoad(i)

for i in range(N):
    print(*visited[i])