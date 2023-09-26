import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))


def checkRange(x,y):
    return 0 <= x < N and 0 <= y < M

def ChangeDirection(d):
    d -= 1
    if d < 0:
        d = 3
    return d    

#북, 동, 남, 서
dx = [-1,0,1,0]
dy = [0,1,0,-1]

N, M  = map(int, input().split())
r, c, d = map(int, input().split())

arr = []

for _ in range(N):
    arr.append(list(map(int, input().split())))

cnt = 0
while True:

    if not arr[r][c]: #청소되지 않은 경우
        arr[r][c] = -1 #청소한다 
        cnt += 1

    clean = True    
    for i in range(4):
        tr = r + dx[i]
        tc = c + dy[i]

        if checkRange(tr,tc):
            if not arr[tr][tc]:    
                clean = False
                break
    if clean: #청소되어있다면
        
        tr = r + dx[(d+2)%4]
        tc = c + dy[(d+2)%4]
        if checkRange(tr,tc) and arr[tr][tc] == 1:#범위를 벗어나지 않고 벽이 아님/
                break
            
        else:
            r = tr
            c = tc
        
    else: #청소해야함
        d = ChangeDirection(d)
        tr = r + dx[d]
        tc = c + dy[d]
        if not arr[tr][tc]:
            r = tr
            c = tc

print(cnt)            


                             