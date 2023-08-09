import sys, io, os, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))
from collections import deque
F, S, G, U, D = map(int, input().split())

visited = [0 for _ in range(F+1)] #F층으로 이루어짐
queue = deque()
queue.append((S,0))
dx = [U, -D]
flag = True
while queue:
    x, cnt = queue.popleft()
    if x == G:
        print(cnt)
        flag = False
        break
    for i in range(2):
        cx = x + dx[i]
        if 0 < cx <= F:
            if not visited[cx]:
                visited[cx] = 1
                queue.append((cx,cnt+1))
if flag:
    print("use the stairs")                