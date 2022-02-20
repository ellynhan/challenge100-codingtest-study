from collections import deque
import sys
import copy

def BFS(v):
    q = deque()
    q.append(v)
    alreadyVisited[v] = 1   
    while q:
        v = q.popleft()
        print(v, end = " ")
        for i in range(1, n + 1):
            if alreadyVisited[i] == 0 and graph[v][i] == 1:
                q.append(i)
                alreadyVisited[i] = 1

def DFS(v):
    alreadyVisited2[v] = 1        
    print(v, end = " ")
    for i in range(1, n + 1):
        if alreadyVisited2[i] == 0 and graph[v][i] == 1:
            DFS(i)

line = sys.stdin.readline().split()
n, m, v = map(int, line)
graph = [[0] * (n + 1) for _ in range(n + 1)] 
alreadyVisited = [0] * (n + 1)
alreadyVisited2 = copy.deepcopy(alreadyVisited)

for _ in range(m):
  a, b = map(int, sys.stdin.readline().split())
  graph[a][b] = graph[b][a] = 1

if __name__ == "__main__":
    DFS(v)
    print()
    BFS(v)
