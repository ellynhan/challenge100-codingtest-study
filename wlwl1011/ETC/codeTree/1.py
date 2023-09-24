import sys, os, atexit, io
input = lambda : sys.stdin.readline().rstrip('\n\r')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda: os.write(1, stdout.getvalue()))

N = int(input())

dx = [0, -1, 0, 1]
dy = [1, 0, -1, 0]

x, y = 0, 0

for _ in range(N):
    d, l = input().split()
    l = int(l)
    if d == 'N':#북
        x += dx[0] * l
        y += dy[0] * l

    elif d == 'W':#서
        x += dx[1] * l
        y += dy[1] * l

    elif d == 'S':#남
        x += dx[2] * l
        y += dy[2] * l

    else:#남 
        x += dx[3] * l
        y += dy[3] * l   

print(x,y)              


