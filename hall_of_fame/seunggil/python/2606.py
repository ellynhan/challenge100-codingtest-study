import sys
from collections import deque

class computer:
    def __init__(self) -> None:
        self.infection = False
        self.graph = []

computerN = int(sys.stdin.readline().rstrip())
network = [computer() for _ in range(computerN + 1) ]
edge = int(sys.stdin.readline().rstrip())

for _ in range(edge):
    a, b = map(int,sys.stdin.readline().rstrip().split())
    network[a].graph.append(b)
    network[b].graph.append(a)

ans = 0
queue = deque([1])
while len(queue) > 0:
    i = queue.popleft()
    if network[i].infection == False :
        ans += 1
        network[i].infection = True
        queue.extend(network[i].graph)
        
print(ans -1)