import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

N = int(input())
arr = []
x = 0
y = 0

dx = [0,1,0,-1]
dy = [1,0,-1,0]

time = 0
totalFlag = True
flag = True
for _ in range(N):
    dir, length = input().split()
    length = int(length)
    for i in range(length):
        if dir == 'N':
            x += dx[0]
            y += dy[0]
        elif dir == 'E':  
            x += dx[1]
            y += dy[1]
        elif dir == 'S':  
            x += dx[2]
            y += dy[2]   
        else:
            x += dx[3]
            y += dy[3] 
        time += 1
        
        if x == 0 and y == 0:
            print(time)
            flag = False
            break

    if flag==False:
        totalFlag = False
        break        
if totalFlag:
    print(-1)        

    
