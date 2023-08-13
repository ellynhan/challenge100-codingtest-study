import sys, os, io, atexit
import copy
from collections import deque
input = lambda: sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s: stdout.write(s.encode("ascii"))
atexit.register(lambda: os.write(1, stdout.getvalue()))

N, M, R = map(int, input().split())


arr = [ [0 for i in range(M)] for i in range(N)]   

cal = [ 0 for i in range(R)]



for i in range(N):
    arr[i] = list(map(int, input().split()))

cal = list(map(int, input().split())) 

for index in cal:

    if index == 3 or index == 4:
        temp = N
        N = M
        M = temp    

    new_arr = [ [ 0 for i in range(M)] for i in range(N)]
    #상하
    if index == 1:
        for i in range(N):
            for j in range(M):
                new_arr[i][j] = arr[(N-1)-i][j]
    #좌우
    elif index == 2:
        for i in range(N):
            for j in range(M):
                new_arr[i][j] = arr[i][(M-1)-j]
    #오른쪽으로 90
    elif index == 3 :
        for i in range(N):
            for j in range(M):
                new_arr[i][j] = arr[(M-1)-j][i]
    #왼족으로 90
    elif index == 4:
        for i in range(N):
            for j in range(M):
                new_arr[i][j] = arr[j][(N-1)-i]
    #시계방향
    elif index == 5:
        for i in range(N//2):
            for j in range(M//2):
                new_arr[i][j] = arr[i+(N//2)][j]
        for i in range(N//2):
            for j in range(M//2,M):
                new_arr[i][j] = arr[i][j-(M//2)]

        for i in range(N//2,N):
            for j in range(M//2):
                new_arr[i][j] = arr[i][j+(M//2)]

        for i in range(N//2,N):
            for j in range(M//2,M):      
                new_arr[i][j] = arr[i-(N//2)][j]          
                        

    #반시계방향
    elif index == 6:
        for i in range(N//2):
            for j in range(M//2):
                new_arr[i][j] = arr[i][j+(M//2)]
        for i in range(N//2):
            for j in range(M//2,M):
                new_arr[i][j] = arr[i+(N//2)][j]

        for i in range(N//2,N):
            for j in range(M//2):
                new_arr[i][j] = arr[i-(N//2)][j]

        for i in range(N//2,N):
            for j in range(M//2,M):      
                new_arr[i][j] = arr[i][j-(M//2)]    
    #갱신
    arr = copy.deepcopy(new_arr)     

for i in range(N):
    for j in range(M):
        print(arr[i][j],end = ' ')
    print()               

