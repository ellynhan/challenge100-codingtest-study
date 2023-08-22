import sys, io, os, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda: os.write(1, stdout.getvalue()))

N = int(input())
arr = list(map(int, input().split()))
d = [1]*(N)

for i in range(N):
    for j in range(i):
        if arr[i] > arr[j]:
            d[i] = max(d[i],d[j]+1)
        #print(d)    

print(max(d))