import sys, os, io, atexit
import copy
from collections import deque
input = lambda: sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s: stdout.write(s.encode("ascii"))
atexit.register(lambda: os.write(1, stdout.getvalue()))

N = int(input())
T = int(input())
answer = int(input())
arr = [ 0 for i in range(N)]
start = 0
n = 1
if T == 0:
    print(0)

while T:
    if answer == 0:
        T-=1
        if T == 0:
            print(start)
            break
        
    start = ( start + 1 ) % N     
    #answer[start] = 1
    if answer == 1:
        T-=1
        if T == 0:
            print(start)
            break

    start = ( start + 1 ) % N 
    #answer[start] = 0
    if answer == 0:
        T-=1
        if T == 0:
            print(start)
            break

    start = ( start + 1 ) % N 
    #answer[start] = 1
    if answer == 1:
        T-=1
        if T == 0:
            print(start)
            break

    start = ( start + 1) % N 
    flag = -1
    temp_n = n
    while temp_n+1 > 0:
        #answer[start] = 0
        if answer == 0:
            T-=1
            if T == 0:
                print(start)
                falg = start
                break
        temp_n -= 1   
        start = ( start + 1) % N  
    if flag >= 0 :
        
        break

    flag = -1
    temp_n = n
    while temp_n+1 > 0:    
        #answer[start+1] = 1
        if answer == 1:
            T-=1
            if T == 0:
                print(start)
                falg = start
                break
        temp_n -= 1  
        start = ( start + 1) % N 
    if flag >= 0 :
        break       
    n += 1
    
        
   



    
    

        


