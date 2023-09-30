import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')
import heapq


x = int(input())
q = []
heapq.heappush(q,64)
while q:
    if sum(q) == x:
        break
    length = heapq.heappop(q)
    
    length = length // 2 #막대기를 반으로 자른다.
    if length == 0:
        continue
    heapq.heappush(q,length)
    if sum(q) >= x:
        continue
    else:
        heapq.heappush(q, length)
print(len(q))        

