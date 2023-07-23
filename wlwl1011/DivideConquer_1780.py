import sys, os, io, atexit
import copy
from collections import deque
input = lambda: sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s: stdout.write(s.encode("ascii"))
atexit.register(lambda: os.write(1, stdout.getvalue()))

# -1, 0, 1


minus_1= 0
plus_1 = 0
zero = 0

def divideAndConquer(x,y,n):
    
    check = arr[x][y] 
    #같은게 있나 보러가볼까?

    for i in range(x,x+n):
        for j in range(y,y+n):
            if check != arr[i][j]:
                check = 2
                break
    if check == 1:
        global plus_1
        plus_1 += 1
    elif check == 0:
        global zero
        zero += 1
    elif check == -1:
        global minus_1
        minus_1 += 1    
    else:
        n = n // 3
        divideAndConquer(x,y,n)
        divideAndConquer(x+n,y,n)
        divideAndConquer(x+n+n,y,n)
        divideAndConquer(x,y+n,n)
        divideAndConquer(x+n,y+n,n)
        divideAndConquer(x+n+n,y+n,n)
        divideAndConquer(x,y+n+n,n)
        divideAndConquer(x+n,y+n+n,n)
        divideAndConquer(x+n+n,y+n+n,n)

N = int(input())
arr = [ [ 0 for i in range(N)] for i in range(N)]
for i in range(N):
    arr[i] = list(map(int, input().split()))

divideAndConquer(0,0,N)      

print(minus_1)
print(zero)   
print(plus_1)                   