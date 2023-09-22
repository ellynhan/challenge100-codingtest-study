import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

def QuadTree(x,y,n):
    
    first = arr[x][y]
    flag = True
    for i in range(x,x+n):
        for j in range(y,y+n):
            if arr[i][j] != first:
                flag = False
                break
    if flag :
        print(first,end='')
    else:
        print('(',end='')
        QuadTree(x,y,n//2)                
        QuadTree(x,y+n//2,n//2)
        QuadTree(x+n//2,y,n//2)
        QuadTree(x+n//2,y+n//2,n//2)
        print(')',end='')
 


N = int(input())
arr = []
for i in range(N):
    arr.append(list(map(int, input())))
QuadTree(0,0,N)