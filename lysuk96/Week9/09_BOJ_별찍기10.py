# https://www.acmicpc.net/problem/2447
# print(3**7)
N = int(input())

s = [['*']*N for _ in range(N)]

def recursion(x,y, n):
    if n == 1:
        return

    for i in range(x+n//3, x + n*2//3):
        for j in range(y+n//3, y + n*2//3):
            s[i][j] = ' '
    
    for i in range(3):
        for j in range(3):
            recursion(x+i*n//3, y+j*n//3, n//3)

recursion(0,0, N)


for i in range(N):
    print(''.join(s[i]))
