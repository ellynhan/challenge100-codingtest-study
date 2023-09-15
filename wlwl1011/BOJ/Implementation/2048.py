import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

dx = [-1,1,0,0]
dy = [0,0,-1,1]

def easy2048(arr, direction):
    check = arr[:]

    #해당 방향으로 최대한 민다.
    if direction == 0:
        #위로 밀 때,
        for i in range(N):
            for j in range(N):
                if arr[i][j] == 0:
                    arr[i]

        




N = int(input())#보드의 크기
arr = [[0 for _ in range(N)] for _ in range(N)]

for i in range(N):
    arr[i] = list(map(int, input().split()))



