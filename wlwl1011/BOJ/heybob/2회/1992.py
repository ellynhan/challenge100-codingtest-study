import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))


def quadTree(x, y, n):
    check = arr[x][y]
    flag = True
    for i in range(x,x+n):
        for j in range(y, y+n):
            if arr[i][j] != check:
                flag = False 
                break
    if flag:
        print(check,end='')
        return
    else:
        print('(', end='')
        quadTree(x, y, n//2)
        quadTree(x, y+n//2, n//2)
        quadTree(x+n//2, y, n//2)
        quadTree(x+n//2, y+n//2, n//2)
        print(')',end='')


N = int(input())
arr = []

for _ in range(N):
    arr.append(list(input()))


quadTree(0, 0, N)    