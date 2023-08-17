import sys, os, io, atexit
import copy
from collections import deque
input = lambda: sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s: stdout.write(s.encode("ascii"))
atexit.register(lambda: os.write(1, stdout.getvalue()))

#1 -> 파란색
#0 -> 하얀색


blue = 0
white = 0
def divideAndConquer(x,y,n):
    
    check = arr[x][y] 
    #같은게 있나 보러가볼까?

    for i in range(x,x+n):
        for j in range(y,y+n):
            if check != arr[i][j]:
                check = -1
                break
    if check == 1:
        global blue
        blue += 1
    elif check == 0:
        global white
        white += 1
    else:
        n = n // 2
        divideAndConquer(x,y,n)
        divideAndConquer(x+n,y,n)
        divideAndConquer(x,y+n,n)
        divideAndConquer(x+n,y+n,n)

N = int(input())
arr = [ [ 0 for i in range(N)] for i in range(N)]
for i in range(N):
    arr[i] = list(map(int, input().split()))

divideAndConquer(0,0,N)                    
print(white)
print(blue)                      