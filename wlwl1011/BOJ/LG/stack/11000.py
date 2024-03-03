import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')
import heapq
N = int(input())
arr = []
for _ in range(N):
    arr.append(list(map(int, input().split())))

arr.sort(key=lambda x: (x[0],x[1]-x[0]))
queue = []
for s, t in arr:
    #print(queue)
    if queue:
        tt, ss = queue[0]
        if tt <= s:
            heapq.heappop(queue)
           
    heapq.heappush(queue,[t,s])

print(len(queue))
