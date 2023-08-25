import sys, io, os, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda: os.write(1, stdout.getvalue()))

N, K = map(int, input().split())
arr = [ [0,0] for _ in range(N) ]
dp = [[0,0] * N]

for i in range(N):
    arr[i] = list(map(int, input().split()))

for i in range(N):
    
