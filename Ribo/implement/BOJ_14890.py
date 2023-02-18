import sys
import copy
input = sys.stdin.readline


def swapRowCol(graph):
    temp = [[0]*n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            temp[j][i] = graph[i][j]
    
    return temp
            
def canRoad(graph, x, y):
    height = graph[x][y+1]
    for j in range(y+1, y+1+l):
        if j > n-1 or graph[x][j] != height:
            return False
    
    return True

def findRoad(graph):
    global path
    for i in range(n):
        flag = True
        cnt = 1
        j = 0
        while j < n-1:
            if graph[i][j] == graph[i][j+1]:
                cnt += 1
            elif graph[i][j] == graph[i][j+1] + 1:
                if canRoad(graph, i, j):
                    cnt = 0
                    j = j + l - 1
                else:
                    flag = False
                    break
                
            elif graph[i][j] == graph[i][j+1] - 1:
                if cnt >= l:
                    cnt = 1
                else:
                    flag = False
                    break

            elif abs(graph[i][j] - graph[i][j+1]) >= 2:
                flag = False
                break
            
            j += 1
        
        if flag == True:
            path += 1
                    

n, l = map(int, input().split())
graph1 = [list(map(int, input().split())) for _ in range(n)]
path = 0

graph2 = swapRowCol(graph1)
findRoad(graph1)
findRoad(graph2)

print(path)
