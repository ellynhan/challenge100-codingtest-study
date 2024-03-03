import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')

def isSqure(x,y,n):

    if 0<= x+n-1 <N and 0 <= y+n-1 <M:
        return arr[x][y] == arr[x+n-1][y] == arr[x][y+n-1] == arr[x+n-1][y+n-1]


def check(x,y,n,m):
    if n <=0 and m <= 0:
        return 1
    ans = 0

    if n < m:
        for i in range(N-n+1):
            for j in range(M-n+1):
                
                if isSqure(x+i,y+j,n):
                    ans =  n*n
           
    else:
        for i in range(N-m+1):
            for j in range(M-m+1):
                if isSqure(x+i,y+j,m):
                    ans =  m*m
            
    if ans:
        return ans
    else:        
        ans = check(x,y,n-1,m-1)   
        return ans             



N, M = map(int, input().split())
arr = []
for _ in range(N):
    arr.append(list(map(int,input())))

print(check(0,0,N,M))