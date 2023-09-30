import sys, io, os, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

def inRange(x,y):
    return 0<= x < N and 0 <= y < M

def changeDirection(d):
    d += 1
    if d > 3:
        d = 0
    return d

N, M = map(int, input().split())

if N == 1 and M == 1:
    print(1)

else:
    arr = [[0 for _ in range(M)] for _ in range(N)]

    dx = [0,1,0,-1]
    dy = [1,0,-1,0]

    x,y = 0,0

    d = 0
    cnt = 2

    arr[0][0] = 1
    while True:
        
        tx = x + dx[d]
        ty = y + dy[d]
        if inRange(tx,ty) and arr[tx][ty] == 0:
            arr[tx][ty] = cnt
            cnt += 1
            x = tx
            y = ty
            if cnt > N*M:
                break
        else:
            d = changeDirection(d)

    for i in range(N):
    
        print(*arr[i])        




