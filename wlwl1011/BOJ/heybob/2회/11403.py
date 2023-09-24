import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))
from collections import deque

def findRoad(v):
    queue = deque()
    queue.append(v)
    # print(v)
    while queue:
        # print(queue)
        vertex = queue.popleft()
        for i in range(N):
            if not visited[v][i] and arr[vertex][i] == 1:
                visited[v][i] = 1
                queue.append(i)
        # for i in range(N):
        #     print(*visited[i])       
                


N = int(input())
visited = [[0 for i in range(N)] for i in range(N)]
arr = []

for _ in range(N):
    arr.append(list(map(int, input().split())))

for i in range(N):
    findRoad(i)

for i in range(N):
    print(*visited[i])