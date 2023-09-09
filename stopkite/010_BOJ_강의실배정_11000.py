import heapq
import sys

n = int(sys.stdin.readline())

time = []
for _ in range(n):
    start, end = map(int, sys.stdin.readline().split())
    time.append([start, end])

time.sort()

room = []
heapq.heappush(room, time[0][1])

for i in range(1, n):
    if time[i][0] >= room[0]:
        heapq.heappop(room)
    heapq.heappush(room, time[i][1])

print(len(room))
