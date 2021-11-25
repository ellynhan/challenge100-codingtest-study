import sys
import heapq

arr = []
for _ in range(int(input())):
    x = int(sys.stdin.readline())
    if x:
        heapq.heappush(arr, (abs(x), x))
    else:
        print(heapq.heappop(arr)[-1] if arr else 0)
