import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))
from collections import deque
import heapq

X = int(input())
q = []
heapq.heappush(q,64)

while heapq:
    #print(q)
    
    if sum(q) <= X:
        break
    smallest = heapq.heappop(q)
    smallest = smallest//2
    heapq.heappush(q,smallest)
    if sum(q) >= X:
        continue
    else:
        heapq.heappush(q,smallest)
        
print(len(q))



