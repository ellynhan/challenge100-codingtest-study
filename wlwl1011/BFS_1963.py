# import sys, io, os, atexit
# input = lambda : sys.stdin.readline().rstrip('\r\n')
# stdout = io.BytesIO()
# sys.stdout.write = lambda s: stdout.write(s.encode("ascii"))
# atexit.register(lambda : os. write(1,stdout.getvalue()))
from collections import deque

def isPrime(number):
    #1혹은 자기 자신으로만 나뉘어지는 수
    number = int(number)
    for i in range(2, number):
        if number%i == 0:
            return False
    return True    

T = int(input())
queue = deque()

for i in range(T):
    visited = [0] * 10000
    queue = deque()
    initial, target = map(list, input().split())
    queue.append((initial, 0))
    
    while queue:

       # print(queue)

        initial, cnt = queue.popleft()

        if initial == target:
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

                if  isPrime(''.join(new_number)) and not visited[int(''.join(new_number))] :     
                    #print(new_number)
                    visited[int(''.join(new_number))] = 1
                    queue.append((new_number, cnt+1))
         