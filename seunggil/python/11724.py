import sys
import collections
from typing import Deque

class node:
    def __init__(self) -> None:
        self.visit = False;
        self.edges = []
    def addEdge(self, index):
        self.edges.append(index)


nodeCount, edgeCount = map(int, sys.stdin.readline().rstrip().split())

graph = [node() for _ in range(nodeCount+1)]

for _ in range(edgeCount):
    a, b = map(int, sys.stdin.readline().rstrip().split())
    graph[a].addEdge(b)
    graph[b].addEdge(a)


ans = 0;
for i in range(1,nodeCount+1):
    bfs = Deque()
    if graph[i].visit == False:
        graph[i].visit = True
        ans += 1
        bfs.extend(graph[i].edges)

    while len(bfs) > 0:
        index = bfs.popleft()
        if graph[index].visit == False:
            graph[index].visit = True
            bfs.extend(graph[index].edges)
    
print(ans)
