import sys
from copy import deepcopy
input = sys.stdin.readline


def rotate(graph):
    temp = [[0]*n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            temp[j][n-i-1] = graph[i][j]
    
    graph = deepcopy(temp)
    return graph

def getMax(graph):
    ret = 0
    for i in range(n):
        for j in range(n):
           if ret < graph[i][j]:
               ret = graph[i][j]
    
    return ret
 
def up(graph):
    for j in range(n):
        p = 0

        for i in range(1, n):
            if graph[i][j]:
                temp = graph[i][j]
                graph[i][j] = 0

                if graph[p][j] == 0:
                    graph[p][j] = temp

                elif graph[p][j] == temp:
                    graph[p][j] *= 2
                    p += 1

                else:
                    p += 1
                    graph[p][j] = temp

    return graph

def dfs(graph, cnt):
    global ans

    if cnt == 5:
        ret = getMax(graph)
        if ans < ret:
            ans = ret
        return

    for _ in range(4):
        dfs(up(deepcopy(graph)), cnt+1)
        graph = rotate(graph)
        

n = int(input())
graph = [list(map(int, input().split())) for _ in range(n)]

ans = 0
dfs(graph, 0)

print(ans)
