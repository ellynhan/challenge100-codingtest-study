import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')

def printStar(x,y,n,isBlank):
    if n == 1:
        if isBlank:
            arr[x][y] = ' '
        else:    
            arr[x][y] = '*'
        return
    if isBlank:
        for i in range(x,x+n):
            for j in range(y,y+n):
                arr[i][j] = ' '
        return        
    printStar(x, y, n//3, False)    
    printStar(x, y + n//3, n//3, False)    
    printStar(x, y + n//3 + n//3, n//3, False)   
    printStar(x + n//3, y, n//3, False) 
    printStar(x + n//3, y + n//3, n//3, True) 
    printStar(x + n//3, y + n//3 + n//3, n//3, False) 
    printStar(x + n//3 + n//3, y, n//3, False) 
    printStar(x + n//3 + n//3, y + n//3, n//3, False) 
    printStar(x + n//3 + n//3, y + n//3 + n//3, n//3, False) 

N = int(input())

arr = [[0 for _ in range(N)] for _ in range(N)]

printStar(0,0,N,False)

for i in range(N):
    print(*arr[i],sep='')