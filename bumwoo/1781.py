import heapq

n = int(input())
array = []
for _ in range(n):
    deadline, cupNoodle = map(int, input().split())
    array.append((deadline, cupNoodle))

array.sort()

queue = []

for i in array:
    heapq.heappush(queue, i[1])
    if i[0] < len(queue):
        heapq.heappop(queue)

print(sum(queue))