import sys
import heapq
input = sys.stdin.readline

n = int(input().rstrip())

heap = []

for _ in range(n):
    
    num = int(input().rstrip())
    
    if num != 0:
        if num < 0:
            heapq.heappush(heap, (-num, num))
        else:
            heapq.heappush(heap, (num, num))
    elif num == 0 and len(heap) == 0:
        print(0)
    else:
        print(heapq.heappop(heap)[1])