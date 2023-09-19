import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

arr = [[0 for i in range(100)] for i in range(100) ]

N = int(input())
for i in range(N):
    x, y = map(int, input().split())
    for i in range(10):
        for j in range(10):
            arr[x+i][y+j] = 1

print(sum(sum(arr[i]) for i in range(100)))            
