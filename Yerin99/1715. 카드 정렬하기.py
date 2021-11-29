import sys
import heapq

heap = []
ans = 0

for _ in range(int(input())):
    heapq.heappush(heap, int(sys.stdin.readline()))

while heap:
    a = heapq.heappop(heap)
    if not heap:
        break
    b = heapq.heappop(heap)
    ans += a + b
    heapq.heappush(heap, a + b)

print(ans)
