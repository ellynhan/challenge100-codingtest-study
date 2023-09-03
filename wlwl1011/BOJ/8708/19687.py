import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))



N, M = map(int, input().split())
arr = []

for i in range(N):
    name, value = input().split()
    arr.append([name, int(value)])
arr.sort(key=lambda x: x[1])

for i in range(M):
    power = int(input())
    start = 0
    end = N
    res = 0
    while start <= end:
        mid = ( start + end ) // 2
        
        if arr[mid][1] >= power:
            end = mid - 1
            res = mid
        else:
            start = mid + 1
    print(arr[res][0])        


