import sys, os, io, atexit
import copy
from collections import deque
input = lambda: sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s: stdout.write(s.encode("ascii"))
atexit.register(lambda: os.write(1, stdout.getvalue()))

#1회차
#뻔 – 데기 – 뻔 – 데기 –  
#뻔 – 뻔 – 데기 – 데기

#2회차
#‘뻔 – 데기 – 뻔 - 데기 –
#뻔 – 뻔 – 뻔 – 데기 – 데기 – 데기’

A = int(input())
T = int(input())
C = int(input())

bbun = 0
dagie = 0
count = 0 
people = 0
while True:
    count += 1
    
    for _ in range(2):
        flag = False
        bbun += 1
        people += 1
        if C == 0:
            T -= 1
            if T == 0:
                flag = True
                break 
               
        flag = False        
        dagie += 1
        people += 1
        if C == 1:
            T -= 1
            if T == 0:
                flag = True
                break

    if flag:
        print((people-1)%A)
        break     

    flag = False

    for _ in range(count+1):
        bbun +=1
        people += 1
        if C == 0:
            T -= 1
            if T == 0:
                flag = True
                break    
    if flag:
        print((people-1)%A)
        break   

    flag = False
    
    for _ in range(count+1):
        dagie += 1   
        people += 1
        if C == 1:
            T -= 1
            if T == 0:
                flag = True
                break
    if flag:
        print((people-1)%A)
        break          
