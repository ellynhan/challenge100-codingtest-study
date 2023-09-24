import sys, io, os, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s: stdout.write(s.encode("ascii"))
atexit.register(lambda: os.write(1,stdout.getvalue()))

dx = [0,1,-1,0]
dy = [1,0,0,-1]

def changeDirection(d):
    if d == 'R':
        return 'L'
    elif d == 'L':    
        return 'R'
    elif d == 'U':
        return 'D'
    elif d == 'D':
        return 'U'         

def checkRange(x,y):
    return 1 <= x <= N and 1 <= y <= N

dd = {
    'R':0,
    'D':1,
    'U':2,
    'L':3
}

N, T = map(int, input().split())
r, c, d = input().split()
r = int(r)
c = int(c)
cnt = 0
while True:
    tx = r + dx[dd[d]]
    ty = c + dy[dd[d]]
    if checkRange(tx,ty):
        cnt += 1
        r = tx
        c = ty
        if cnt >= T:
            break
    else:
        d = changeDirection(d)
        cnt += 1   
        if cnt >= T:
            break 
print(r,c)

