import sys
import heapq
input = lambda : sys.stdin.readline().rstrip('\r\n')

m, n = map(int, input().split())
answer = []
graph = [[] for _ in range(n+1)]
inDegree = [0 for _ in range(n+1)]
queue = []

for i in range(m):
    first, second = map(int, input().split())
    graph[first].append(second)
    inDegree[second] += 1

for i in range(1, n+1):
    if inDegree[i] == 0:
        heapq.heappush(queue, i)

while queue:
    tmp = heapq.heappop(queue)
    answer.append(tmp)
    for i in graph[tmp]:
        inDegree[i] -=1
        if inDegree[i] == 0:
            heapq.heappush(queue,i)

print("".join(map(str,answer)))            
