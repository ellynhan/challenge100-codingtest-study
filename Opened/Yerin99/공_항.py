import sys
import heapq
from collections import deque

# 인풋 받는 파트

k = int(input())
heap = []
queue_list = []
tmp_queue = deque()
input_data = []

for _ in range(k):
    input_data.extend(list(map(int, sys.stdin.readline().split())))

for x in input_data:
    tmp_queue.append(x)
    if x == 0:
        queue_list.append(tmp_queue)
        tmp_queue = deque()

# heap 쓰고 queue 쓰는 핵심 파트 & 출력

for i in range(k):
    front = queue_list[i][0]
    if front != 0:
        heapq.heappush(heap, front)

while heap:
    top_priority = heapq.heappop(heap)
    print(top_priority)
    for i in range(k):
        front = queue_list[i][0]
        if front == top_priority:
            queue_list[i].popleft()
            new_front = queue_list[i][0]
            if new_front != 0:
                heapq.heappush(heap, new_front)
            break
