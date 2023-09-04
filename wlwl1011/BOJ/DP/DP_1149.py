import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

N = int(input())


arr = [ [0,0,0] for _ in range(N) ]


for i in range(N):
    arr[i] = list(map(int, input().split()))

for i in range(1,N):
    arr[i][0] = min(arr[i-1][1], arr[i-1][2]) + arr[i][0]

    arr[i][1] = min(arr[i-1][0], arr[i-1][2]) + arr[i][1]

    arr[i][2] = min(arr[i-1][0], arr[i-1][1]) + arr[i][2]
    #print(arr[i])

print(min(arr[N-1]))    