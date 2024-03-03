import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')
from collections import deque

def check(node):
    queue = deque()
    queue.append(node)

    while queue:
        n = queue.popleft()

        for i in range(N):
            if visited[node][i] == 0 and arr[n][i] == 1:
                visited[node][i] = 1 
                queue.append(i)   


N = int(input())

arr = []
visited = [[0 for _ in range(N)] for _ in range(N)]
for _ in range(N):
    arr.append(list(map(int, input().split())))

for i in range(N):
    check(i)

for i in range(N):
    print(*visited[i])    