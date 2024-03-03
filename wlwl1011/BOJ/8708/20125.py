import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))
from collections import deque

N = int(input())
arr = [[0 for _ in range(N)] for _ in range(N)]
heart_x, heart_y = 0, 0

for i in range(N):
    arr[i] = list(input())

flag = True
for i in range(N):
    for j in range(N):
        if arr[i][j] == '*':
            heart_x = i+1
            heart_y = j
            flag = False
            break
    if flag == False:
        break    

#print(heart_x, heart_y)
#왼쪽 팔 길이 구하러 가보자.
left_hand = 0
for i in range(1,N):
    if heart_y-i < 0:
        break
    if arr[heart_x][heart_y-i] == '_':
        break
    left_hand += 1

#오른쪽 팔 길이 구하러 가보자
right_hand = 0
for i in range(1,N):
    if heart_y+i>= N:
        break
    if arr[heart_x][heart_y+i] == '_':
        break
    right_hand += 1    

#허리 길이를 구하러 가보자
waist = 0
for i in range(1,N):
    if heart_x+i>= N:
        break
    if arr[heart_x+i][heart_y] == '_':
        break
    waist += 1   

#왼쪽 다리 길이 구하러 가보자.
left_leg = 0
for i in range(1,N):
    if heart_x+waist+i >= N or heart_y+1 >= N:
        break
    if arr[heart_x+waist+i][heart_y-1] == '_':
        break
    left_leg += 1

#오른쪽 다리 길이 구하러 가보자
right_leg = 0
for i in range(1,N):
    if heart_x+waist+i >= N or heart_y+1 >= N:
        break
    if arr[heart_x+waist+i][heart_y+1] == '_':
        break
    right_leg += 1    

print(heart_x+1, heart_y+1)
print( left_hand, right_hand, waist, left_leg, right_leg )    
