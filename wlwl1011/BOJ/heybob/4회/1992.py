import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')


def checkSame(x,y,n):
    
    check = arr[x][y]

    for i in range(x,x+n):
        for j in range(y,y+n):
            if arr[i][j] != check:
                return False
    return True        


def compress(x,y,n):
    
    if checkSame(x,y,n):
        print(arr[x][y],end='')
        return
    else:
        #왼쪽 위, 오른쪽 위, 왼쪽 아래, 오른쪽 아래
        print('(',end='')
        compress(x,y,n//2)
        compress(x,y+n//2,n//2)
        compress(x+n//2,y,n//2)
        compress(x+n//2,y+n//2,n//2)
        print(')',end='')
        return


N = int(input())

arr = []

for _ in range(N):
    arr.append(list(map(int, input())))

compress(0,0,N)