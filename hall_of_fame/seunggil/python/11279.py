import heapq
import sys

n = int(sys.stdin.readline().rstrip())

maxQueue = []
for i in range(n) :
    query = int(sys.stdin.readline().rstrip())
    if query > 0:
        heapq.heappush(maxQueue,-query)
    else :
        if len(maxQueue) > 0:
            print(-heapq.heappop(maxQueue))
        else :
            print(0)