
import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s: stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))
import heapq

N = int(input())
arr = []
temp = 0
for i in range(N):
   
    for j in list(map(int, input().split())):
        if len(arr) < N:
            heapq.heappush(arr,j)
        else:
            if arr[0] < j:
                heapq.heappop(arr)
                heapq.heappush(arr,j)




print(arr[0])