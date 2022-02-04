import heapq
import sys

input_len = int(input())
min_heap = []
max_heap = []

for i in range(input_len):
    num = int(sys.stdin.readline())
    if i%2 == 0:
        heapq.heappush(max_heap, num*-1)
    else:
        heapq.heappush(min_heap, num)
    if len(min_heap)>0 and len(max_heap)>0 and min_heap[0] < max_heap[0]*-1:
        tmp = heapq.heappop(min_heap)
        heapq.heappush(min_heap, heapq.heappop(max_heap)*-1)
        heapq.heappush(max_heap, tmp*-1)
    print(max_heap[0]*-1)
