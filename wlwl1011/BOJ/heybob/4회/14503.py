import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')

dx = [-1,0,1,0]
dy = [0,1,0,-1]

def check(tr,tc):
    return 0<= tr < N and 0 <= tc < N 

N, M = map(int, input().split())
r, c, d = map(int, input().split())

arr = []

for _ in range(N):
    arr.append(list(map(int, input().split())))

#0 청소 안됨
#1 벽
cnt = 0
while True:
    if arr[r][c] == 0:
        arr[r][c] = -1 #청소
        cnt += 1

    isClean = True    
    for i in range(4):
        tr = r + dx[i]
        tc = c + dy[i]

        if check(tr,tc):
            if arr[tr][tc] == 0:
                isClean = False
                break    
    if isClean:
        tr = r + dx[(d+2)%4]      
        tc = c + dy[(d+2)%4]
        if check(tr,tc) and arr[tr][tc] != 1:
            r = tr
            c = tc
        else:
            break #종료

    else:
        d = (d+3)%4
        tr = r + dx[d]
        tc = c + dy[d]
        if check(tr,tc) and arr[tr][tc] == 0: #청소되지 않았을 경우
            r = tr
            c = tc
print(cnt)            