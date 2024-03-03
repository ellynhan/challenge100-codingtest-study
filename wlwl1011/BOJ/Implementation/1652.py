import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')

N = int(input())
arr = []
for _ in range(N):
    arr.append(list(input()))
width = 0
height = 0
for i in range(N):
    cnt = 0
    flag = True
    for j in range(N):
        if arr[i][j] == '.':
            cnt +=1    
        else:
            cnt = 0
            flag = True
        if cnt >= 2:
            if flag:
                width += 1
                flag = False
               
    cnt = 0     
    flag = True
    for j in range(N):
        if arr[j][i] == '.':
            cnt +=1    
        else:
            cnt = 0
            flag = True
        if cnt >= 2:
            if flag:
                height += 1
                flag = False     
print(width, height)         