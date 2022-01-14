import heapq
import sys

input_len = int(input())
max_heap = []
for _ in range(input_len):
    num = int(sys.stdin.readline())
    if num == 0:
        if len(max_heap) > 0:
            print(heapq.heappop(max_heap)* -1)
        else:
            print(0)
    else:
        heapq.heappush(max_heap, num*-1)
