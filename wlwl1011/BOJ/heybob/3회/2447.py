import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

def printStar(x,y,n,isBlank):

    if n == 1:
        if isBlank:
            arr[x][y] = ' '
        
        else:
            for i in range(x,x+n):
                for j in range(y,y+n):
                    arr[i][j] = '*'     
        return    
    
    if isBlank:
        
        for i in range(x,x+n):
            for j in range(y,y+n):
                arr[i][j] = ' '
        return
    
    printStar(x,y,n//3,False)
    printStar(x,y+n//3,n//3,False)
    printStar(x,y+n//3+n//3,n//3,False)

    printStar(x+n//3,y,n//3,False)
    printStar(x+n//3,y+n//3,n//3,True)
    printStar(x+n//3,y+n//3+n//3,n//3,False)

    printStar(x+n//3+n//3,y,n//3,False)
    printStar(x+n//3+n//3,y+n//3,n//3,False)
    printStar(x+n//3+n//3,y+n//3+n//3,n//3,False)


N = int(input())

arr = [[0 for _ in range(N)] for _ in range(N)]
printStar(0,0,N,False)
for i in range(N):
    for j in range(N):
        print(arr[i][j],end='')
    print()    