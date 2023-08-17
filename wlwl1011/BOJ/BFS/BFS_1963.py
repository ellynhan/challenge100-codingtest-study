# import sys, io, os, atexit
# input = lambda : sys.stdin.readline().rstrip('\r\n')
# stdout = io.BytesIO()
# sys.stdout.write = lambda s: stdout.write(s.encode("ascii"))
# atexit.register(lambda : os. write(1,stdout.getvalue()))
from collections import deque
import math

def isPrime(number):
    #1혹은 자기 자신으로만 나뉘어지는 수
    number = int(number)
    for i in range (2, int(math.sqrt(number)) + 1):
        if number % i == 0:
            return False
    return True

T = int(input())
queue = deque()
visited = [[0] * 10000 for _ in range(T)]
arr_inital = [['' for _  in range(4)] for _ in range(T)]
arr_target = [['' for _  in range(4)] for _ in range(T)]

for x in range(T):
    initial, target = map(list, input().split())
    arr_inital[x] = initial
    arr_target[x] = target

for x in range(T):    
    queue = deque()
    queue.append((arr_inital[x],arr_target[x], 0))
    flag = True
    while queue:

        #print(queue)

        initial,target, cnt = queue.popleft()

        if initial == target:
            flag = False
            print(cnt)
            break

        
        for i in range(4):

            #temp = initial[:]

            for j in range(10):
                
                new_number = initial[:]

                #일의 자리 수 일 때 0은 피한다.
                #원래 수도 피한다
                if i == 0 and j == 0 or j == new_number[i]:    
                    continue  

                new_number[i] = str(j) #0에서 9까지의 수로 대체해봅시다!

                if  isPrime(''.join(new_number)) and not visited[x][int(''.join(new_number))] :     
                    #print(new_number)
                    visited[x][int(''.join(new_number))] = 1
                    queue.append((new_number, target, cnt+1))
    if flag:
        print('Impossible')              
         