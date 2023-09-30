import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')

global white
global blue

def check(x,y,n):
    check = arr[x][y]
    for i in range(x,x+n):
        for j in range(y,y+n):
            if arr[i][j] != check:
                return -1
    return check

def splitPaper(x,y,n):
    global white
    global blue
    #하얀색으로 칠해진 칸은 0
    if check(x,y,n) == 0:
        white += 1
        return
    elif check(x,y,n) == 1:  
        blue += 1
        return
    splitPaper(x,y,n//2)
    splitPaper(x+n//2,y,n//2)
    splitPaper(x,y+n//2,n//2)
    splitPaper(x+n//2,y+n//2,n//2)



        




N = int(input())
arr = []
white = 0
blue = 0
for _ in range(N):
    arr.append(list(map(int, input().split())))
splitPaper(0,0,N)
print(white)    
print(blue)