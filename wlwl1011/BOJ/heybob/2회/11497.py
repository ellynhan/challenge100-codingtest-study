import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

T = int(input())

for _ in range(T):
    N = int(input())
    arr = list(map(int, input().split()))
    arr.sort()
    dif = 0
    for i in range(N-2):
        dif = max(dif, arr[i+2]-arr[i])
    print(dif)    