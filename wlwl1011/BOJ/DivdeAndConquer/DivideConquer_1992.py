import sys, os, io, atexit
import copy
from collections import deque
input = lambda: sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s: stdout.write(s.encode("ascii"))
atexit.register(lambda: os.write(1, stdout.getvalue()))

N = int(input())

board = [[ 0 for i in range(N) ] for i in range(N)]


for i in range(N):
    board[i] = list(map(int, input()))


def quadTree(x, y, n):
    check = board[x][y]
    for i in range(x, x+n):
        for j in range(y, y+n):
            if check != board[i][j]: #다른 색상을 가진다면
                check = -1
                break

    if check == -1:
        print("(", end = '')
        n = n//2
        quadTree(x,y,n)  
        quadTree(x,y+n,n)
        quadTree(x+n,y,n)
        quadTree(x+n,y+n,n)
        print(")",end='')
    elif check == 1:
        print(1, end = '')
    else:
        print(0, end = '')        
   
quadTree(0,0,N)


