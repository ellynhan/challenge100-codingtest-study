import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))
from collections import deque

N = int(input())
arr = [[0 for _ in range(N)] for _ in range(N)]

for i in range(N):
    arr[i] = list(map(int, input().split()))

visited = [[0 for _ in range(N)] for _ in range(N)]

def bfs(x):
    queue = deque()
    queue.append(x)
    check = [0 for _ in range(N)]

    while queue:
        q = queue.popleft()

        for i in range(N):
            if check[i] == 0 and arr[q][i] == 1:
                queue.append(i)
                check[i] = 1
                visited[x][i] = 1

for i in range(N):
    bfs(i)

for i in visited:
    print(*i)    