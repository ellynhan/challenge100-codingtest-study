import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))


dx = [-1,0,1,0] #북 동 남 서
dy = [0,1,0,-1]

arr = []

N, M = map(int, input().split())
r, c, d = map(int, input().split())

for i in range(N):
    arr.append(list(map(int,input().split())))

cnt = 0
while True:
    if arr[r][c] == 0: #청소되지 않은 경우
        arr[r][c] = -1 #청소한다.
        cnt += 1
    flag = True #청소안된 방이 있는지 check    
    for i in range(4):
        tr = r + dx[i]
        tc = c + dy[i]

        if 0<= tr < N and 0 <= tc < M:
            if arr[tr][tc] == 0:
                flag = False
                break   
    if flag : #모두 다 청소된 경우
        #바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진하고 1번으로 돌아간다.
        
        tr = r + dx[(d+2)%4]
        tc = c + dy[(d+2)%4]

        if 0<= tr < N and 0 <= tc < M and arr[tr][tc] != 1:
            r = tr
            c = tc
        else:
            break
    else:
        d -= 1
        if d < 0:
            d = 3
        tr = r + dx[d]
        tc = c + dy[d]

        if arr[tr][tc] == 0:
            r = tr
            c = tc            
                         



print(cnt)