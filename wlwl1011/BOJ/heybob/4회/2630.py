import sys
input = lambda: sys.stdin.readline().rstrip('\r\n')

global white
global blue

def checkSame(x,y,n):
    check = arr[x][y]
    for i in range(x,x+n):
        for j in range(y, y+n):
            if check != arr[i][j]:
                return -1
    return check        
            
def solve(x,y,n):
    global white
    global blue
    if checkSame(x,y,n) == -1:
        solve(x,y,n//2)
        solve(x+n//2,y,n//2)
        solve(x,y+n//2,n//2)
        solve(x+n//2,y+n//2,n//2)
    elif checkSame(x,y,n) == 1:
        blue += 1
    else:
        white += 1        


N = int(input())
arr = []
blue = 0
white = 0

for _ in range(N):
    arr.append(list(map(int, input().split())))

solve(0,0,N)    
print(white)
print(blue)

    
