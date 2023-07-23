import sys, os, io, atexit
import copy
from collections import deque
input = lambda: sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s: stdout.write(s.encode("ascii"))
atexit.register(lambda: os.write(1, stdout.getvalue()))

global answer

def tetromino(x,y):
    global answer
    ####
    if x - 3 >= 0:
        answer = max( answer, arr[x][y] + arr[x-1][y] + arr[x-2][y] + arr[x-3][y])
    if x + 3 < N:
        answer = max( answer, arr[x][y] + arr[x+1][y] + arr[x+2][y] + arr[x+3][y])
    if y - 3 >= 0:
        answer = max( answer, arr[x][y] + arr[x][y-1] + arr[x][y-2] + arr[x][y-3])
    if y + 3 < M:
        answer = max( answer, arr[x][y] + arr[x][y+1] + arr[x][y+2] + arr[x][y+3])
    ##
    ##
    if x + 1 < N:
        if y + 1 < M:         
            answer = max( answer, arr[x][y] + arr[x+1][y] + arr[x][y+1] + arr[x+1][y+1])  
        if y - 1 >= 0:
            answer = max( answer, arr[x][y] + arr[x+1][y] + arr[x][y-1] + arr[x+1][y-1])      
    if x - 1 >=0 :
        if y + 1 < M:
            answer = max( answer, arr[x][y] + arr[x-1][y] + arr[x][y+1] + arr[x-1][y+1]) 
        if y - 1 >= 0:
            answer = max( answer, arr[x][y] + arr[x-1][y] + arr[x][y-1] + arr[x-1][y-1])     
    #    #
    #    ##
    # #   #
    if x - 2 >= 0:
        if y + 1 < M: 
            answer = max( answer, arr[x][y] + arr[x-1][y] + arr[x-2][y] + arr[x-2][y+1])
            answer = max( answer, arr[x][y] + arr[x-1][y] + arr[x-1][y+1] + arr[x-2][y+1])
        if y - 1 >= 0:
            answer = max( answer, arr[x][y] + arr[x-1][y] + arr[x-2][y] + arr[x-2][y-1])
            answer = max( answer, arr[x][y] + arr[x-1][y] + arr[x-1][y-1] + arr[x-2][y-1])
    if x + 2 < N:
        if y + 1 < M: 
            answer = max( answer, arr[x][y] + arr[x+1][y] + arr[x+2][y] + arr[x+2][y+1])
            answer = max( answer, arr[x][y] + arr[x+1][y] + arr[x+1][y+1] + arr[x+2][y+1])
        if y - 1 >= 0:
            answer = max( answer, arr[x][y] + arr[x+1][y] + arr[x+2][y] + arr[x+2][y-1])
            answer = max( answer, arr[x][y] + arr[x+1][y] + arr[x+1][y-1] + arr[x+2][y-1])
    if y - 2 >= 0:
        if x + 1 < N:
            answer = max( answer, arr[x][y] + arr[x][y-1] + arr[x][y-2] + arr[x+1][y-2])
            answer = max( answer, arr[x][y] + arr[x][y-1] + arr[x+1][y-1] + arr[x+1][y-2])
        if x - 1 >= 0:    
            answer = max( answer, arr[x][y] + arr[x][y-1] + arr[x][y-2] + arr[x-1][y-2])
            answer = max( answer, arr[x][y] + arr[x][y-1] + arr[x-1][y-1] + arr[x-1][y-2])
    if y + 2 < M:
        if x + 1 < N:
            answer = max( answer, arr[x][y] + arr[x][y+1] + arr[x][y+2] + arr[x+1][y+2])
            answer = max( answer, arr[x][y] + arr[x][y+1] + arr[x+1][y+1] + arr[x+1][y+2])
        if x - 1 >= 0:    
            answer = max( answer, arr[x][y] + arr[x][y+1] + arr[x][y+2] + arr[x-1][y+2])   
            answer = max( answer, arr[x][y] + arr[x][y+1] + arr[x-1][y+1] + arr[x-1][y+2])
    ###
     #
    if x - 2 >= 0:
        if y + 1 < M:
            answer = max( answer, arr[x][y] + arr[x-1][y] + arr[x-2][y] + arr[x-1][y+1])
        if y - 1 >= 0:
            answer = max( answer, arr[x][y] + arr[x-1][y] + arr[x-2][y] + arr[x-1][y-1])    
    if x + 3 < N:
        if y + 1 < M:
            answer = max( answer, arr[x][y] + arr[x+1][y] + arr[x+2][y] + arr[x+2][y+1])
        if y - 1 >= 0:
            answer = max( answer, arr[x][y] + arr[x+1][y] + arr[x+2][y] + arr[x+2][y-1])    
    if y - 3 >= 0:
        if x - 1 >= 0:
            answer = max( answer, arr[x][y] + arr[x][y-1] + arr[x][y-2] + arr[x-1][y-1])
        if x + 1 < N :  
            answer = max( answer, arr[x][y] + arr[x][y-1] + arr[x][y-2] + arr[x+1][y-1])   
    if y + 3 < M:
        if x - 1>= 0:
            answer = max( answer, arr[x][y] + arr[x][y+1] + arr[x][y+2] + arr[x-1][y+1]) 
        if x + 1 < N:   
            answer = max( answer, arr[x][y] + arr[x][y+1] + arr[x][y+2] + arr[x+1][y+1])  
    

answer = 0
N, M = map(int, input().split()) 
arr = [ [0 for _ in range(M)] for _ in range(N)]     

for i in range(N):
    arr[i] = list(map(int, input().split()))


for i in range(N):
    for j in range(M):
        tetromino(i,j)

print(answer)
      