from math import sqrt
import sys
from collections import deque

class Node:
    def __init__(self, x, y) -> None:
        self.x = x
        self.y = y

    def __str__(self) -> str:
        return str(self.x) + " " + str(self.y)

class Edge:
    def __init__(self, x, y, len) -> None:
        self.start = x
        self.end = y
        self.len = len

    def __str__(self) -> str:
        return str(self.start) + " " + str(self.end) + " " + str(self.len)

n = int(input())
inputData = []
for _ in range(n):
    a, b = map(float, sys.stdin.readline().rstrip().split())
    inputData.append(Node(a,b))


edges = []

for i in range(n):
    for j in range(n):
        if(i == j) :
            continue
        edges.append(Edge(i,j, sqrt((inputData[i].x - inputData[j].x) ** 2 + (inputData[i].y - inputData[j].y) ** 2)))

edges.sort(key=lambda x: (x.len, x.start, x.end))

parent = [i for i in range(n)]

def find(a):
    if parent[a] == a:
        return a
    parent[a] = find(parent[a])
    return parent[a]

def union(a, b):
    parentA = find(a)
    parentB = find(b)

    if parentA < parentB : 
        parent[parentB] = parentA
    elif parentA > parentB : 
        parent[parentA] = parentB

ans = 0.0
cnt = 0
for i in edges:
    start = find(i.start)
    end = find(i.end)
    if start != end :
        ans += i.len
        union(start, end)
        cnt += 1
    if cnt == n-1:
        break
    
print(ans)