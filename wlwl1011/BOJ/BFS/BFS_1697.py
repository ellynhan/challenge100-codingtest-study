import sys, os, io, atexit
import copy
from collections import deque
input = lambda: sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s: stdout.write(s.encode("ascii"))
atexit.register(lambda: os.write(1, stdout.getvalue()))

count = 0
max_num = 100000
visited = [0] * (max_num+1)

n, k = map(int,input().split())

queue = deque()

queue.append(n)

while queue:
    temp = queue.popleft()
    if temp == k:
        print(visited[temp])
        break
    for i in (temp-1, temp+1, temp*2):
        if 0 <= i <= max_num and visited[i] == 0:
            visited[i] = visited[temp] + 1
            queue.append(i)
