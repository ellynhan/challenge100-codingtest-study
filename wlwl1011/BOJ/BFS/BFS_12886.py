import sys, os, io, atexit
import copy
from collections import deque
# # input = lambda: sys.stdin.readline().rstrip('\r\n')
# # stdout = io.BytesIO()
# # sys.stdout.write = lambda s: stdout.write(s.encode("ascii"))
# # atexit.register(lambda: os.write(1, stdout.getvalue()))
# # import heapq

#강호는 모든 그룹에 있는 돌의 개수를 같게 만들려고 한다.

#1. 크기가 같지 않은 두 그룹을 고른다.
#2. 돌의 개수가 작은 쪽을 X, 큰 쪽을 Y라고 정한다. 
#3. X에 있는 돌의 개수를 X+X개로, Y에 있는 돌의 개수를 Y-X개로 만든다.

arr = list(map(int, input().split()))
if sum(arr) % 3 != 0:
    print(0)
    exit()

answer = sum(arr)//3

queue = deque()
arr.sort()
queue.append(arr)
dictionary = dict()
while queue:
    
    isNotTrue = True
    arr = queue.popleft()
    if arr[0] == arr[1] == arr[2]:
        isNotTrue = False
        print(1)
        break
        
    if arr[0] != arr[1]:
        x = arr[0]
        y = arr[1]
        if y-x >= 0 :
            new_arr = [x+x, y-x, arr[2]]
            new_arr.sort()
            if tuple(new_arr) not in dictionary.keys() :
                if new_arr == [answer,answer,answer]:
                    isNotTrue = False
                    print(1)
                    break
                dictionary[tuple(new_arr)] = 1
                queue.append(new_arr)
    if arr[0] != arr[2]:
        x = arr[0]
        y = arr[2]
        if y-x >= 0 :
            new_arr = [x+x,y-x,arr[1]]
            new_arr.sort()
            if tuple(new_arr) not in dictionary.keys():
                if new_arr == [answer,answer,answer]:
                    isNotTrue = False
                    print(1)
                    break
                dictionary[tuple(new_arr)] = 1
                queue.append(new_arr)
    if arr[1] != arr[2]:
        x = arr[1]
        y = arr[2]
        if y-x >= 0 :
            new_arr = [x+x, y-x, arr[0]]
            new_arr.sort()
            if tuple(new_arr) not in dictionary.keys():
                if new_arr == [answer,answer,answer]:
                    isNotTrue = False
                    print(1)
                    break
                dictionary[tuple(new_arr)] = 1
                queue.append(new_arr)                

if isNotTrue:
    print(0)
       
